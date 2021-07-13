#ifndef _TEXTURE
#define _TEXTURE

#include "./modules/glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h"

#include "./modules/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include/SDL.h"
#include "./modules/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/include/SDL_image.h"


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