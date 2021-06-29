#ifndef _MODEL
#define _MODEL

#define STATUS_READY 0
#define STATUS_BINDED 1
#define STATUS_WAITING 2

#include <glew.h>
#include <SDL.h>

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
	GameWindow* windowParent;

	const static Shader STANDARD_SHADER;

	
private:

	void InitGraphics(const Shader* shader);

public:

	Model(GameWindow* windowParent);

	Model(GameWindow* windowParent, float xpos, float ypos, float xsize, float ysize);

	int GetStatus() const;

	void SetStatus(int status);
	
	void Bind();

	virtual void Draw();
};


const Shader Model::STANDARD_SHADER = Shader("./resource/vertex/stadardVertexShader.glsl", "./resource/fragment/stadardFragmentShader.glsl");


#endif