#include "Model.h"



void Model::RenewBuffer()
{

	int w;
	int h;

	SDL_GL_GetDrawableSize(windowParent->GetWindow(), &w, &h);

	float ratioX = xSize / (float)w;
	float ratioY = ySize / (float)h;

	float ratioXPos = xPos / (float)w;
	float ratioYPos = yPos / (float)h;


	const GLfloat vertexData[(3 + 2) * 4] = {
		-ratioX,  ratioY,   0.f, 0.f, 0.f, //11
		 ratioX,  ratioY,   0.f, 1.f, 0.f, //01
		 ratioX, -ratioY,   0.f, 1.f, 1.f, //00
		-ratioX, -ratioY,   0.f, 0.f, 1.f  //10
	};


	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

}

void Model::InitGraphics(const Shader* shader, Texture* texture)
{

	this->attachedShader = (Shader*)shader;
	this->texture = texture;

	int w;
	int h;

	SDL_GetWindowSize(windowParent->GetWindow(), &w, &h);

	float ratioX = xSize / (float)w;
	float ratioY = ySize / (float)h;

	float ratioXPos = xPos / (float)w;
	float ratioYPos = yPos / (float)h;

	std::cout << "w : " <<  ratioX<< "h : " << ratioY<< std::endl;


	const GLfloat vertexData[(3 + 2) * 4] = {
		-ratioX,  ratioY,   0.f, 0.f, 0.f, //11
		 ratioX,  ratioY,   0.f, 1.f, 0.f, //01
		 ratioX, -ratioY,   0.f, 1.f, 1.f, //00
		-ratioX, -ratioY,   0.f, 0.f, 1.f  //10
	};

	const GLfloat textureData[] = {
		0.f, 0.f, //11
		1.f, 0.f, //01
		1.f, 1.f, //00
		0.f, 1.f,  //10
	};

	const GLuint indexData[6] = {
		0,1,2,0,2,3
	};


	glGenVertexArrays(1, &vertexArrayId);

	glBindVertexArray(vertexArrayId);


	glGenBuffers(3, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);


	glBindBuffer(GL_ARRAY_BUFFER, textureBufferId);

	glBufferData(GL_ARRAY_BUFFER, sizeof(textureData), textureData, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);

	glEnableVertexAttribArray(1);


	texture->TextureIndex(attachedShader, "ourTexture", 0);
	//texture->Bind();

	auto error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! 33%s\n", gluErrorString(error));
	}

}

Model::Model(GameWindow* _windowParent,Shader* shader, Texture* texture) : xSize(500.f), ySize(500.f), xPos(0.f), yPos(0.f), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(shader, texture);
}

Model::Model(GameWindow* _windowParent, Shader* shader, Texture* texture, float xpos, float ypos, float xsize, float ysize)
	: xSize(xsize), ySize(ysize), xPos(xpos), yPos(ypos), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(shader, texture);
}

Model::~Model()
{

}

int Model::GetStatus() const
{
	return status;

}

void Model::SetStatus(int status)
{
	this->status = status;
}

Texture* Model::GetTexture() const
{
	return texture;
}

void Model::SetTexture(Texture* texture)
{
	auto lastIndex = this->texture->GetIndex();

	this->texture = texture;
	this->texture->TextureIndex(attachedShader, "ourShader", lastIndex);
}


void Model::Bind()
{

	int w;
	int h;

	SDL_GL_GetDrawableSize(windowParent->GetWindow(), &w, &h);

	float ratioXPos = xPos / (float)w;
	float ratioYPos = yPos / (float)h;


	texture->Bind();
	attachedShader->Use();


	glBindVertexArray(vertexArrayId); 

	glUniform2f(glGetUniformLocation(attachedShader->ID, "sharedLocation"), ratioXPos, ratioYPos);
}

void Model::Position(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Model::Draw()
{
	Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
}

void Model::Resize(float x, float y)
{
	this->xSize = x;
	this->ySize = y;
	RenewBuffer();
}
