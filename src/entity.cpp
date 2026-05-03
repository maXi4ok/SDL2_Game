#include "Entity.hpp"

Entity::Entity(Vec2 position, SDL_Texture *texture, bool needsToBeCentered) : texture(texture)
{
	if (needsToBeCentered)
	{
		pos = Vec2((position.x - this->getSize().w / 2), (position.y - this->getSize().h / 2));
	}
}
Entity::Entity(Vec2 position, SDL_Texture *texture, textureSize size, bool needsToBeCentered) : texture(texture), size(size)
{
	if (needsToBeCentered)
	{
		pos = Vec2((position.x - this->getSize().w / 2), (position.y - this->getSize().h / 2));
	}
}

void Entity::update() {}

void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}
