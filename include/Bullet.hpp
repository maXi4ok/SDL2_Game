#pragma once
#include "Entity.hpp"
#include "Wall.hpp"

class Bullet : public Entity
{
public:
	Bullet(Vec2 position, SDL_Texture *texture) : Entity(position, texture) {};
	void update(float deltaTime, bool isColliding, const Wall &collider);

private:
	float speed = -300.0f;
	int xOffset = rand() % 3 - 1;
};
