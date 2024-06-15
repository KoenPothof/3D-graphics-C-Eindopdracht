#include "MovingObjectComponent.h"
#include "GameObject.h"


MovingObjectComponent::MovingObjectComponent()
{
}

MovingObjectComponent::~MovingObjectComponent()
{
}

void MovingObjectComponent::init()
{
	gameObject->position = glm::vec3(6, -2, -6);
	
}

void MovingObjectComponent::update(float deltaTime)
{
	if (movingForward)
	{
		gameObject->position.x += runningSpeed * deltaTime;
		if (gameObject->position.x >= targetX2)
		{
			gameObject->position.x = targetX2;
			movingForward = false;
		}
	}
	else
	{
		gameObject->position.x -= runningSpeed * deltaTime;
		if (gameObject->position.x <= targetX1)
		{
			gameObject->position.x = targetX1;
			movingForward = true;
		}
	}
}