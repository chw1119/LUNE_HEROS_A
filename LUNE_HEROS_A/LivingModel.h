#ifndef _LIVEING_MODEL
#define _LIVEING_MODEL

#include <vector>
#include <chrono>

#include "Model.h"
#include "Utility.h"
#include "Texture.h"

class LivingModel : public Model
{
private:
	int offsetNow;
	int textureCount;

	int fpsRate;

	std::chrono::microseconds lastDraw;
	
public:
	LivingModel();
	LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count);
	LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture, int count, int fpsRate);

	//LivingModel();

	virtual void Bind();
	virtual void Draw();

};


#endif