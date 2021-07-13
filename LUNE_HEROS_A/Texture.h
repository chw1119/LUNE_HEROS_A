#ifndef _TEXTURE
#define _TEXTURE

#include <glew.h>

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

#include "Shader.h"


class Texture
{
private:

	GLuint textureId;
	GLuint textureBufferId;

	int rowCount;
	int lineCount;

	int index;

	int row;
	int line;

private:

	void InitBuffer();
	void RenewBuffer();	

public:

	Texture();

	Texture(const std::string& textureUrl);

	Texture(const std::string& textureUrl,int rowCount, int lineCount);

	void TextureIndex(Shader* shader,const std::string& uniformName ,int index);

	void Bind();

	int GetIndex() const;

	int GetRowCount() const;

	int GetLineCount() const;

	void SetRow(int row);

	void SetLine(int Line);

	GLfloat GetRowPerSize();

	GLfloat GetLinePerSize();

	void AttachToVAO(GLuint vaoId, int pointerId);
};

#endif