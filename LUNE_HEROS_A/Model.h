#ifndef _MODEL
#define _MODEL

#define STATUS_READY 0
#define STATUS_BINDED 1
#define STATUS_WAITING 2

#include <glew.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Shader.h"
#include "Texture.h"
#include "Drawable.h"
#include "Resizable.h"
#include "GameWindow.h"

class Model : public Drawable ,Resizable
{
private:

	GLuint vertexArrayId;

	GLuint vertexBufferId;
	GLuint indexBufferId;

	GLuint textureBufferId;

	float xPos;
	float yPos;

	float xSize;
	float ySize;

	int status;

	Texture* texture;
	Shader* attachedShader;
	GameWindow* windowParent;
	
private:

	void RenewBuffer();

	void InitGraphics(const Shader* shader, Texture* texture);

public:

	Model(GameWindow* windowParent, Shader* shader, Texture* texture);

	Model(GameWindow* windowParent, Shader* shader, Texture* texture, float xpos, float ypos, float xsize, float ysize);

	virtual ~Model();

	int GetStatus() const;

	void SetStatus(int status);

	Texture* GetTexture()const;

	void SetTexture(Texture* texture);
	

	void Position(float x, float y);

	virtual void Bind();

	virtual void Draw();

	virtual void Resize(float x, float y);

};



#endif