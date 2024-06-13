#pragma once

#include "Component.h"
#include "Texture.h"

class DrawComponent : public Component
{
public:
	DrawComponent();
	~DrawComponent();
	virtual void draw() = 0;
};

