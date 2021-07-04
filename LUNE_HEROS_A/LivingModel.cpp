#include "LivingModel.h"


LivingModel::LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count) 
	: Model(windowParent,shader,texture)
{
	textureCount = count;

	for (int a = 0; a < count; a++)
	{
		textureList.push_back(&texture[a]);
	}

	offsetNow = 0;

	fpsRate = 1000 / 25;

}

LivingModel::LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count, int fpsRate)
	: Model(windowParent, shader, texture)
{
	textureCount = count;

	for (int a = 0; a < count; a++)
	{
		textureList.push_back(&texture[a]);
	}

	offsetNow = 0;

	this->fpsRate = fpsRate;

}

Texture* LivingModel::GetNextTexture()
{
	return textureList.at(offsetNow++ % textureList.size());
}

void LivingModel::Bind()
{

	if ((Utility::GetCurrentMilliTimes() - lastDraw).count() > fpsRate)
	{
		SetTexture(GetNextTexture());
	}

	Model::Bind();
}

void LivingModel::Draw()
{
	Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	lastDraw = Utility::GetCurrentMilliTimes();

}
