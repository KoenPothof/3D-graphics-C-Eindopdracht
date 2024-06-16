#pragma once
#include "DrawComponent.h"
#include "TextComponent.h"
class DoubleTextComponent : public DrawComponent
{
public:
    std::shared_ptr<TextComponent> text1;
    std::shared_ptr<TextComponent> text2;
    std::shared_ptr<TextComponent> text3;
    DoubleTextComponent(float x1, float y1, float x2, float y2, float x3, float y3);
    ~DoubleTextComponent();
    virtual void draw() override;
};
