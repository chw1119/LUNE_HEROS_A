#ifndef _LIVEING_MODEL
#define _LIVEING_MODEL

#include <vector>

#include "Model.h"
#include "Texture.h"

class LivingModel : public Model
{
private:

	int offsetNow;

	std::vector<Texture> textureList;

public:
	LivingModel(GameWindow* windowParent, Shader* shader, Texture* texture);

	//LivingModel();

};


#endif