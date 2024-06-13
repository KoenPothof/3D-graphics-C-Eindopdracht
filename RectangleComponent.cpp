#include "RectangleComponent.h"
#include "Texture.h"


RectangleComponent::RectangleComponent(int x, int y, int z, int direction, bool flat, int width, int height, Texture* texture, float wallWidth, bool switchNormalDirection) : texture(texture)
{
    glm::vec2 pos1 = glm::vec2(0, 0);
    glm::vec2 pos2 = glm::vec2(1, 0);
    glm::vec2 pos3 = glm::vec2(1, 1);
    glm::vec2 pos4 = glm::vec2(0, 1);


    glm::vec3 normalDirection = glm::vec3(1, 1, 1);
    if (switchNormalDirection)
        normalDirection = glm::vec3(-1, -1, -1);


    if (direction == 0 && flat == false) {
        verts.push_back(Vertex::PTN(glm::vec3(x, y, z), pos1, glm::vec3(0, 0, -1))); // bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x + width, y, z), pos2, glm::vec3(0, 0, -1))); // far bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x + width, y + height, z), pos3, glm::vec3(0, 0, -1))); // far top point
        verts.push_back(Vertex::PTN(glm::vec3(x, y + height, z), pos4, glm::vec3(0, 0, -1))); // top point

        verts.push_back(Vertex::PT(glm::vec3(x, y, z), pos1)); // bottom point
        verts.push_back(Vertex::PT(glm::vec3(x, y, z + wallWidth), pos2)); // far bottom point
        verts.push_back(Vertex::PT(glm::vec3(x, y + height, z + wallWidth), pos3)); // far top point
        verts.push_back(Vertex::PT(glm::vec3(x, y + height, z), pos4)); // top point

        verts.push_back(Vertex::PT(glm::vec3(x + width, y, z), pos1)); // bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y, z + wallWidth), pos2)); // far bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y + height, z + wallWidth), pos3)); // far top point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y + height, z), pos4)); // top point

        verts.push_back(Vertex::PTN(glm::vec3(x, y, z + wallWidth), pos1, glm::vec3(0, 0, 1))); // bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x + width, y, z + wallWidth), pos2, glm::vec3(0, 0, 1))); // far bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x + width, y + height, z + wallWidth), pos3, glm::vec3(0, 0, 1))); // far top point
        verts.push_back(Vertex::PTN(glm::vec3(x, y + height, z + wallWidth), pos4, glm::vec3(0, 0, 1))); // top point

        verts.push_back(Vertex::PT(glm::vec3(x, y + height, z), pos1)); // bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y + height, z), pos2)); // far bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y + height, z + wallWidth), pos3)); // far top point
        verts.push_back(Vertex::PT(glm::vec3(x, y + height, z + wallWidth), pos4)); // top point

        verts.push_back(Vertex::PT(glm::vec3(x, y, z), pos1)); // bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y, z), pos2)); // far bottom point
        verts.push_back(Vertex::PT(glm::vec3(x + width, y, z + wallWidth), pos3)); // far top point
        verts.push_back(Vertex::PT(glm::vec3(x, y, z + wallWidth), pos4)); // top point
    }
    else if (direction == 1 && flat == false) {
        verts.push_back(Vertex::PTN(glm::vec3(x, y, z), pos2, glm::vec3(-1, 0, 0) * normalDirection)); // bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x, y, z - width), pos1, glm::vec3(-1, 0, 0) * normalDirection)); // far bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x, y + height, z - width), pos4, glm::vec3(-1, 0, 0) * normalDirection)); // far top point
        verts.push_back(Vertex::PTN(glm::vec3(x, y + height, z), pos3, glm::vec3(-1, 0, 0) * normalDirection)); // top point
    }
    else if (flat == true) {
        verts.push_back(Vertex::PTN(glm::vec3(x, y, z), pos2, glm::vec3(0, -1, 0) * normalDirection)); // bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x - width, y, z), pos1, glm::vec3(0, -1, 0) * normalDirection)); // far bottom point
        verts.push_back(Vertex::PTN(glm::vec3(x - width, y, z + height), pos4, glm::vec3(0, -1, 0) * normalDirection)); // far top point
        verts.push_back(Vertex::PTN(glm::vec3(x, y, z + height), pos3, glm::vec3(0, -1, 0) * normalDirection)); // top point
    }
}

RectangleComponent::~RectangleComponent()
{
}

void RectangleComponent::draw()
{
    texture->bind();
    tigl::drawVertices(GL_QUADS, verts);
}

