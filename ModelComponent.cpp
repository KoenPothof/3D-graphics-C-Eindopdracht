#include "ModelComponent.h"

ModelComponent::ModelComponent(const std::string& modelPath) : model(ObjModel(modelPath))
{
}

ModelComponent::~ModelComponent()
{
}

void ModelComponent::draw()
{
	model.draw();
}