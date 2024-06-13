#pragma once

#include "DrawComponent.h"
#include "tigl.h"
#include "Texture.h"
using tigl::Vertex;
#include <vector>

class RectangleComponent : public DrawComponent
{
	std::vector<Vertex> verts;
	Texture* texture;
public:
	RectangleComponent(int x, int y, int z, int direction, bool flat, int width, int height, Texture* texture, float wallWidth = 1.0f, bool switchNormalDirection = false);
	~RectangleComponent();

	virtual void draw() override;
};


