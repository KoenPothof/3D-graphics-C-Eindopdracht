#pragma once

#include "DrawComponent.h"
#include "RectangleComponent.h"
#include "DoorComponent.h"
#include <vector>
#include <memory>

const float ROOM_HEIGHT = 2.0f;

class RoomComponent : public DrawComponent
{
private:
    std::vector<std::shared_ptr<RectangleComponent>> rectangles;
    std::vector<std::shared_ptr<DoorComponent>> doors;

public:

    enum DoorLocation
    {
        LEFT,
        RIGHT,
        BACK,
        FRONT,
        RIGHTLEFT,
        FRONTBACK,
        HALLWAY,
        STAGE,
        MAINROOM
    };

    RoomComponent(const int sideWallsWidth, const int frontWallsWidth, const int wallBesideDoorWidth, DoorLocation doorLocation);
    ~RoomComponent();

    virtual void draw() override;
};

