#ifndef _TEXTURE
#define _TEXTURE

#include <glew.h>

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

#include "Shader.h"
#include "Shader.h"


class Texture
{
private:
	GLuint textureId;

	int index;

public:

	Texture(const std::string& textureUrl);

	void TextureIndex(Shader* shader,const std::string& uniformName ,int index);

	void Bind();

	int GetIndex() const;
};

#endif