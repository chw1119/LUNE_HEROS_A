#include "Texture.h"


void Texture::InitBuffer()
{

	auto rowSize = GetRowPerSize();
	auto lineSize = GetLinePerSize();

	auto xPos = row * rowSize;
	auto yPos = line * lineSize;

	const GLfloat textureData[] = {
		xPos, yPos, //00
		xPos + rowSize, yPos, //10
		xPos + rowSize, yPos + lineSize, //11
		xPos, yPos + lineSize,  //01
	};

	glBindBuffer(GL_ARRAY_BUFFER, textureBufferId);

	glBufferData(GL_ARRAY_BUFFER, sizeof(textureData), textureData, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

}

void Texture::RenewBuffer()
{

	auto rowSize = GetRowPerSize();
	auto lineSize = GetLinePerSize();

	auto xPos = row * rowSize;
	auto yPos = line * lineSize;

	const GLfloat textureData[] = {
		xPos, yPos, //00
		xPos + rowSize, yPos, //10
		xPos + rowSize, yPos + lineSize, //11
		xPos, yPos + lineSize,  //01
	};

	glBindBuffer(GL_ARRAY_BUFFER, textureBufferId);

	glBufferData(GL_ARRAY_BUFFER, sizeof(textureData), textureData, GL_STATIC_DRAW);
}

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

	SDL_FreeSurface(surface);

	index = 0;
	row = 0;
	line = 0;

	InitBuffer();
}


Texture::Texture(const std::string& textureUrl, int rowCount, int lineCount)
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

	SDL_FreeSurface(surface);

	index = 0;
	row = 0;
	line = 0;

	this->rowCount = rowCount;
	this->lineCount = lineCount;

	InitBuffer();
}

void Texture::TextureIndex(Shader* shader, const std::string& uniformName, int index)
{
	shader->Use();
	this->index = index;
	auto num = glGetUniformLocation(shader->ID, uniformName.c_str());
	glUniform1i(num, index);
}


void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

int Texture::GetIndex() const
{
	return index;
}

void Texture::SetRow(int row)
{
	this->row = row;
	RenewBuffer();
}

void Texture::SetLine(int line)
{
	this->line = line;
	RenewBuffer();
}



GLfloat Texture::GetRowPerSize()
{
	return 1.0f / rowCount;
}

GLfloat Texture::GetLinePerSize()
{
	return 1.0f / lineCount;
}