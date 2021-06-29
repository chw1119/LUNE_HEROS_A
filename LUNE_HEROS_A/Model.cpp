#include "Model.h"


void Model::InitGraphics(const Shader* shader)
{

	const GLfloat vertexData[( 3 + 2 ) * 4] = {
		0.f,   ySize, 0.f, 0.f, 0.f,
		xSize, ySize, 0.f, 1.f, 0.f,
		xSize, 0.f,   0.f, 1.f, 1.f,
		0.f,   0.f,   0.f, 0.f, 1.f
	};

	const GLuint indexData[6] = {
		0,1,2,0,2,3
	};\


	glGenVertexArrays(1, &vertexArrayId);

	glBindVertexArray(vertexArrayId);


	glGenBuffers(2, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_DYNAMIC_DRAW);


	this->attachedShader = (Shader*)shader;



}

Model::Model(GameWindow* _windowParent) : xSize(0.f), ySize(0.f), xPos(0.f), yPos(0.f), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(&STANDARD_SHADER);
}

Model::Model(GameWindow* _windowParent, float xpos, float ypos, float xsize, float ysize)
	: xSize(xsize), ySize(ysize), xPos(xpos), yPos(ypos), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics(&STANDARD_SHADER);
}

int Model::GetStatus() const
{
	return status;

}

void Model::SetStatus(int status)
{
	this->status = status;
}
