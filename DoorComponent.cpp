#include "DoorComponent.h"
#include "Texture.h"

extern Texture* texture;
extern Texture* textureWall;

DoorComponent::DoorComponent(const int frontWallsWidth, const int sideWallsWidth, const int height, const int direction, const int wallBesideDoorWidth, const DoorLocation doorLocation)
{
    int doorWidth = 3;
    int doorHeight = 5;
    int x = 0;
    int y = 0;
    int z = 0;

    switch (doorLocation)
    {
    case FRONT:
        // front wall with door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 0, false, frontWallsWidth - doorWidth - wallBesideDoorWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth + frontWallsWidth - doorWidth - wallBesideDoorWidth, y + doorHeight, z, 0, false, doorWidth, height - doorHeight, textureWall)); // wall above door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth + frontWallsWidth - wallBesideDoorWidth, y, z, 0, false, wallBesideDoorWidth, height, textureWall)); // wall beside door
        break;

    case BACK:
        // back wall with door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth, 0, false, frontWallsWidth - doorWidth - wallBesideDoorWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth + frontWallsWidth - doorWidth - wallBesideDoorWidth, y + doorHeight, z - sideWallsWidth, 0, false, doorWidth, height - doorHeight, textureWall)); // wall above door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth + frontWallsWidth - wallBesideDoorWidth, y, z - sideWallsWidth, 0, false, wallBesideDoorWidth, height, textureWall)); // wall beside door
        break;

    case LEFT:
        // left wall with door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z, 1, false, sideWallsWidth - doorWidth - wallBesideDoorWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y + doorHeight, z - sideWallsWidth + doorWidth + wallBesideDoorWidth, 1, false, doorWidth, height - doorHeight, textureWall)); // wall above door
        rectangles.push_back(std::make_shared<RectangleComponent>(x - frontWallsWidth, y, z - sideWallsWidth + wallBesideDoorWidth, 1, false, wallBesideDoorWidth, height, textureWall)); // wall beside door
        break;

    case RIGHT:
        // right wall with door
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z, 1, false, sideWallsWidth - doorWidth - wallBesideDoorWidth, height, textureWall)); // front wall
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y + doorHeight, z - sideWallsWidth + doorWidth + wallBesideDoorWidth, 1, false, doorWidth, height - doorHeight, textureWall)); // wall above door
        rectangles.push_back(std::make_shared<RectangleComponent>(x, y, z - sideWallsWidth + wallBesideDoorWidth, 1, false, wallBesideDoorWidth, height, textureWall)); // wall beside door
        break;
    }

}

DoorComponent::~DoorComponent()
{
}

void DoorComponent::draw()
{
    for (const auto& rectangle : rectangles)
    {
        rectangle->draw();
    }
}
