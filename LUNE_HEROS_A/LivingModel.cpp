#include "LivingModel.h"


LivingModel::LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count) 
	: Model(windowParent,shader,texture)
{
	textureCount = count;

	offsetNow = 0;

	fpsRate = 1000 / 25;

	lastDraw = Utility::GetCurrentMilliTimes();

}

LivingModel::LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count, int fpsRate)
	: Model(windowParent, shader, texture)
{
	textureCount = count;

	offsetNow = 0;

	this->fpsRate = 1000 / fpsRate;

	lastDraw = Utility::GetCurrentMilliTimes();

}

void LivingModel::Bind()
{

	if ((Utility::GetCurrentMilliTimes() - lastDraw).count()/1000 > fpsRate)
	{
		auto texture = GetTexture();
		texture->SetRow(++offsetNow % texture->GetRowCount());

		lastDraw = Utility::GetCurrentMilliTimes();
	}

	Model::Bind();


}

void LivingModel::Draw()
{
	Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
