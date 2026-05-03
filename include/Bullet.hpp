#pragma once
#include "Entity.hpp" 

class Bullet : public Entity
{
public:
	Bullet(Vec2 position, SDL_Texture *texture): Entity(position, texture) {};
	void update(float deltaTime);
};
