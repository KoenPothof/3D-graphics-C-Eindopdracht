#pragma once

#include <gl/glew.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

class Texture
{
public:
	Texture(const std::string& filename, int textureWidth, int textureHeight, int textureSize);
	~Texture();
	void bind();

	/// <summary>
	/// Creates the texture coordinates for the texture atlas
	/// </summary>
	/// <param name="textureX">the x index of the texture atlas</param>
	/// <param name="textureY">the y index of the texture atlas</param>
	/// <returns>An array of 4 vectors. ret[0] bottom left, ret[1] bottom right, ret[2] top right, ret[3] top left</returns>
	glm::vec2* setTexture(int textureX, int textureY);
private:
	unsigned int id, texture;
	int width, height, nrChannels, textureHeight, textureWidth, texturesPerRow, textureSize;
	unsigned char* data, * currentTextureData;
};


