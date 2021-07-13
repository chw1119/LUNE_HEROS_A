#ifndef _MODEL
#define _MODEL

#define STATUS_READY 0
#define STATUS_BINDED 1
#define STATUS_WAITING 2

#include "./modules/glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h"
#include "./modules/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include/SDL.h"
#include "./modules/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/include/SDL_image.h"


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

	Model();

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