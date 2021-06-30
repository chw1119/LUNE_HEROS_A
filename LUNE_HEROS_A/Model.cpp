#include "Model.h"


void Model::InitGraphics(const Shader* shader, std::string textureLocation)
{

	const GLfloat vertexData[( 3 + 2 ) * 4] = {
		0.f,   ySize, 0.f, 0.f, 0.f,
		xSize, ySize, 0.f, 1.f, 0.f,
		xSize, 0.f,   0.f, 1.f, 1.f,
		0.f,   0.f,   0.f, 0.f, 1.f
	};

	const GLuint indexData[6] = {
		0,1,2,0,2,3
	};


	glGenVertexArrays(1, &vertexArrayId);

	glBindVertexArray(vertexArrayId);


	glGenBuffers(2, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));


	glEnableVertexAttribArray(0);

	glEnableVertexAttribArray(1);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);

	SDL_Surface* sur = IMG_Load(textureLocation.c_str());

	glGenTextures(1, &textureBufferId);
	glBindTexture(GL_TEXTURE_2D, textureBufferId);

	int mode = GL_RGB;
	if (sur->format->BytesPerPixel == 4)
		mode = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, mode, sur->w, sur->h, 0, mode, GL_UNSIGNED_BYTE, sur->pixels);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	delete sur;

	this->attachedShader = (Shader*)shader;

}

Model::Model(GameWindow* _windowParent,Shader* shader,std::string textureUrl) : xSize(0.f), ySize(0.f), xPos(0.f), yPos(0.f), windowParent(_windowParent)
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
	glBindTexture(GL_TEXTURE_2D, textureBufferId);
	glBindVertexArray(vertexArrayId);
}

void Model::Draw()
{
	Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}