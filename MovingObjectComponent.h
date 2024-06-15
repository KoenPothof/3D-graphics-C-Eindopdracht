#include <glm/glm.hpp>
#include "Component.h"

class MovingObjectComponent : public Component{
public:
    MovingObjectComponent();
    ~MovingObjectComponent();

    void init();
    void update(float deltaTime);
    void movementToggle();

    bool rennn = true;

private:
    glm::vec3 position;
    float targetX1 = 6;
    float targetX2 = 12;
    float runningSpeed = 2.0f;
    bool movingForward = true;
};


