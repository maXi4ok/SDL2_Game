#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vec2 position, SDL_Texture *texture) : pos(position), texture(texture) {};
	Entity(Vec2 position, SDL_Texture *texture, bool needsToBeCentered);
	Entity(Vec2 position, SDL_Texture *texture, textureSize size) : pos(position), texture(texture), size(size) {};
	Entity(Vec2 position, SDL_Texture *texture, textureSize size, bool needsToBeCentered);
	Vec2 getPos() { return pos; };
	SDL_Texture *getTexture() { return texture; };
	textureSize getSize() { return size; };
	void setPos(float x, float y);
	void update();

private:
	Vec2 pos;
	textureSize size = textureSize();
	SDL_Texture *texture;
};
