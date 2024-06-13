#pragma once
#include "DrawComponent.h"
#include "tigl.h"
#include <string>
#include "Texture.h"
#include "ObjModel.h"

class ModelComponent : public DrawComponent
{
	ObjModel model;
public:
	ModelComponent(const std::string& modelPath);
	~ModelComponent();

	virtual void draw() override;
};

