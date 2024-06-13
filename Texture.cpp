#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define IMAGE_PART (float)textureSize / (float)textureWidth

Texture::Texture(const std::string& filename, const int textureWidth, const int textureHeight, const int textureSize)
{
	this->textureWidth = textureWidth;
	this->textureHeight = textureHeight;
	this->textureSize = textureSize;
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 4);
	if (data)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture);
	stbi_image_free(data);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

glm::vec2* Texture::setTexture(int textureX, int textureY)
{
	float x = (float)((IMAGE_PART)*textureX);
	float y = (float)((IMAGE_PART)*textureY);

	glm::vec2* ret = new glm::vec2[4];
	ret[0] = glm::vec2(x, y); // 0,0
	ret[1] = glm::vec2(x + IMAGE_PART, y); // 1,0
	ret[2] = glm::vec2(x + IMAGE_PART, y + IMAGE_PART); // 1,1
	ret[3] = glm::vec2(x, y + IMAGE_PART); // 0,1

	return ret;
}


