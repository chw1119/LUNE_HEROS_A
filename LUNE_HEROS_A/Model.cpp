#include "Model.h"

void Model::InitGraphics()
{
	glGenVertexArrays(1, &vertexArrayId);

	glBindVertexArray(vertexArrayId);

	glGenBuffers(2, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);


}

Model::Model(GameWindow* _windowParent) : xSize(0.f), ySize(0.f), xPos(0.f), yPos(0.f), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics();
}

Model::Model(GameWindow* _windowParent, float xpos, float ypos, float xsize, float ysize)
	: xSize(xsize), ySize(ysize), xPos(xpos), yPos(ypos), windowParent(_windowParent)
{
	SetStatus(STATUS_READY);
	InitGraphics();
}
