#include "Texture.h"

Texture::Texture(const std::string& textureUrl)
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	auto surface = IMG_Load(textureUrl.c_str());


	if (surface)
	{
		int mode = GL_RGB;
		if (surface->format->BytesPerPixel == 4)
			mode = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	index = 0;
}

void Texture::TextureIndex(Shader* shader, const std::string& uniformName, int index)
{
	this->index = index;
	auto num = glGetUniformLocation(shader->ID, uniformName.c_str());
	glUniform1i(num, index);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, textureId);
}
