#include "DoubleTextComponent.h"

DoubleTextComponent::DoubleTextComponent(float x1, float y1, float x2, float y2, float x3, float y3)
{
    text1 = std::make_shared<TextComponent>(x1, y1);
    text2 = std::make_shared<TextComponent>(x2, y2);
    text3 = std::make_shared<TextComponent>(x3, y3);
}

DoubleTextComponent::~DoubleTextComponent()
{
}

void DoubleTextComponent::draw()
{
    text1->draw();
    text2->draw();
    text3->draw();
}