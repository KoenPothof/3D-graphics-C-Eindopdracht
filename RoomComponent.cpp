#include "RoomComponent.h"
#include "RoomComponent.h"
#include "Texture.h"

extern Texture* texture;
extern Texture* textureWall;
extern Texture* textureFloor;
extern Texture* textureCeiling;

RoomComponent::RoomComponent(const int sideWallsWidth, const int frontWallsWidth, const int wallBesideDoorWidth, DoorLocation doorLocation)
{
    // Left and right walls
    //rectangles.push_back(std::make_shared<RectangleComponent>(1, false, ));

    int height = 10;
    int x = 0;
    int y = 0;
    int z = 0;

    int doorHeight = 5;
    int doorWidth = 2;
    //int wallBesideDoorWidth = 2;

    switch (doorLocation)
    {
    case FRONT:

        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::FRONT));

        // rest of the walls
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth, height, textureWall)); // left wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth, height, textureWall)); // back wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth, height, textureWall)); // right wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling)); // ceiling
        break;

    case BACK:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::BACK));

        // rest of the walls
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 0, false, frontWallsWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth, height, textureWall)); // left wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth, height, textureWall)); // right wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling)); // ceiling
        break;

    case LEFT:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::LEFT));

        // rest of the walls
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 0, false, frontWallsWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth, height, textureWall)); // back wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth, height, textureWall)); // right wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling)); // ceiling
        break;

    case RIGHT:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::RIGHT));

        // rest of the walls
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 0, false, frontWallsWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth, height, textureWall)); // left wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth, height, textureWall)); // back wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling, 1.0f, true)); // ceiling
        break;

    case RIGHTLEFT:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::LEFT));
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::RIGHT));



        // rest of the walls
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 0, false, frontWallsWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth, height, textureWall)); // back wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling, 1.0f, true)); // ceiling
        break;

    case FRONTBACK:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::FRONT));
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::BACK));

        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth, height, textureWall, 1.0f, true)); // left wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth, height, textureWall)); // right wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling)); // ceiling
        break;

    case HALLWAY:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::RIGHT));

        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth, height, textureWall, 1.0f, true)); // left wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling, 1.0f, true)); // ceiling
        break;

    case STAGE:
        doors.push_back(std::make_shared<DoorComponent>(frontWallsWidth, sideWallsWidth, height, 0, wallBesideDoorWidth, DoorComponent::LEFT));

        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling)); // ceiling
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth, height, textureWall)); // right wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth, height, textureWall)); // back wall
        break;
    case MAINROOM:
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureFloor)); // floor
        rectangles.push_back(std::make_shared<RectangleComponent>(x, height, z, 1, true, frontWallsWidth, -1 * sideWallsWidth, textureCeiling, 1.0f, true)); // ceiling
        break;

    };
}

RoomComponent::~RoomComponent()
{
}

void RoomComponent::draw()
{
    for (const auto& rectangle : rectangles)
    {
        rectangle->draw();
    }
    for (const auto& door : doors)
    {
        door->draw();
    }
}
