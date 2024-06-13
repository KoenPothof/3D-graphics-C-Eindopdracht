#pragma once
#include <memory>

class GameObject;

class GameManager
{
public:
	GameManager();
	~GameManager();
	void init();
	void update(float elapsedTime);
};