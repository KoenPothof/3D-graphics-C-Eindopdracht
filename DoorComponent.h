#pragma once

#include "DrawComponent.h"
#include "RectangleComponent.h"
#include <vector>
#include <memory>

class DoorComponent : public DrawComponent
{
private:
    std::vector<std::shared_ptr<RectangleComponent>> rectangles;


public:
    enum DoorLocation
    {
        LEFT,
        RIGHT,
        BACK,
        FRONT
    };

    DoorComponent(const int frontWallsWidth, const int sideWallsWidth, const int height, const int direction, const int wallBesideDoorWidth, const DoorLocation doorLocation);
    ~DoorComponent();

    virtual void draw() override;
};

