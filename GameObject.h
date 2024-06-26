#pragma once

#include <memory>
#include <list>
#include <glm/glm.hpp>
#include <iostream>
#include <string>



class GameManager;
class Component;
class DrawComponent;


class GameObject
{
public:

	std::shared_ptr<DrawComponent> drawComponent;
	std::list<std::shared_ptr<Component>> components;
	std::shared_ptr<GameManager> gameManager;

	GameObject();
	GameObject(std::shared_ptr<GameManager> gameManager);
	GameObject(std::shared_ptr<GameObject>& other);
	~GameObject();

	glm::vec3 position;
	glm::vec3 rotation = glm::vec3(0, 0, 0);
	glm::vec3 scale = glm::vec3(1, 1, 1);

	void addComponent(std::shared_ptr<Component> component);
	std::list<std::shared_ptr<Component>> getComponents();
	void update(float elapsedTime);
	void draw(const glm::mat4 & = glm::mat4(1.0f));

	template<class T>
	std::shared_ptr<T> getComponent()
	{
		for (auto component : components)
		{
			std::shared_ptr<T> casted = std::dynamic_pointer_cast<T>(component);
			if (casted) {
				return casted;
			}
		}
		return nullptr;
		
	}

	template<class T>
	void removeComponent()
	{
		components.remove_if([](Component* c)
			{
				T* t = dynamic_cast<T*>(c);
				return t != nullptr;
			});
	}
};
