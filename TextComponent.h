#pragma once
#include "DrawComponent.h"
#include "stb_truetype.h"
#include <string>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>


class TextComponent : public DrawComponent
{
private:
	float x1, y1;
public:
	stbtt_bakedchar cdata[96];
	GLuint texId;
	std::string text = "Hello, world!";
	TextComponent(const float x1, const float y1);
	~TextComponent();

	float countdown;
	float elapsedTime;
	float deltaTime;

	void init();
	virtual void draw() override;
	void update(float deltaTime);
	void setText(std::string text);
};

