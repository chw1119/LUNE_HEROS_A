#include "Model.h"


void Model::InitGraphics(const Shader* shader, std::string textureLocation)
{

	this->attachedShader = (Shader*)shader;

	const GLfloat vertexData[(3 + 2) * 4] = {
		0.f,   ySize, 0.f, 0.f, 1.f,
		xSize, ySize, 0.f, 1.f, 1.f,
		xSize, 0.f,   0.f, 1.f, 0.f,
		0.f,   0.f,   0.f, 0.f, 0.f
	};

	const GLuint indexData[6] = {
		0,1,2,0,2,3
	};


	glGenVertexArrays(1, &vertexArrayId);

	glBindVertexArray(vertexArrayId);


	glGenBuffers(2, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));


	glEnableVertexAttribArray(0);

	glEnableVertexAttribArray(1);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);

	surface = IMG_Load(textureLocation.c_str());


	glGenTextures(1, &textureBufferId);
	glBindTexture(GL_TEXTURE_2D, textureBufferId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);



	if (surface)
		{
		int mode = GL_RGB;
		if (surface->format->BytesPerPixel == 4)
			mode = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
		glUniform1i(glGetUniformLocation(attachedShader->ID, "ourTexture"),0);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}



	glBindTexture(GL_TEXTURE_2D, 0);
	//delete sur;


	SDL_FreeSurface(surface);


	auto error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
	}

}

Model::Model(GameWindow* _windowParent,Shader* shader,std::string textureUrl) : xSize(0.5f), ySize(0.5f), xPos(0.f), yPos(0.f), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(shader, textureUrl);
}

Model::Model(GameWindow* _windowParent, Shader* shader, std::string textureUrl, float xpos, float ypos, float xsize, float ysize)
	: xSize(xsize), ySize(ysize), xPos(xpos), yPos(ypos), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(shader, textureUrl);
}

int Model::GetStatus() const
{
	return status;

}

void Model::SetStatus(int status)
{
	this->status = status;
}


void Model::Bind()
{

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureBufferId);

	attachedShader->Use();
	glBindVertexArray(vertexArrayId); 

}

void Model::Draw()
{
	Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
}