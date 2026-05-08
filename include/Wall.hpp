#pragma once
#include "Entity.hpp"

class Wall : public Entity
{
public:
	Wall(Vec2 position, SDL_Texture *texture): Entity(position, texture) {};
};