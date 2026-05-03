#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"


class RenderWindow
{
public:
	RenderWindow(const char *title, int h, int w);
	
	SDL_Texture *loadTexture(const char *filePath);
	int getRefreshRate();
	void clear();
	void render(Entity& entity);
	void display();
	void cleanUp();
	
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};