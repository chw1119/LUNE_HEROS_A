#ifndef _MODEL
#define _MODEL

#define STATUS_READY 0
#define STATUS_BINDED 1
#define STATUS_WAITING 2

#include <glew.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Shader.h"
#include "Drawable.h"
#include "GameWindow.h"

class Model : public Drawable
{
private:

	GLuint vertexArrayId;

	GLuint vertexBufferId;
	GLuint indexBufferId;\

	GLuint textureBufferId;

	float xPos;
	float yPos;

	float xSize;
	float ySize;

	int status;

	Shader* attachedShader;
	SDL_Surface* surface;
	GameWindow* windowParent;
	
private:

	void InitGraphics(const Shader* shader, std::string textureLocation);

public:

	Model(GameWindow* windowParent, Shader* shader, std::string textureLocation);

	Model(GameWindow* windowParent, Shader* shader, std::string textureLocation, float xpos, float ypos, float xsize, float ysize);

	int GetStatus() const;

	void SetStatus(int status);
	
	void Bind();

	virtual void Draw();
};



#endif