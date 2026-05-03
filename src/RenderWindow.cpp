#include <iostream>
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int h, int w) : window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window init failed. Error: " << SDL_GetError() << '\n';
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "Renderer init failed. Error: " << SDL_GetError() << '\n';
	}
}
SDL_Texture* RenderWindow::loadTexture (const char * filePath) 
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == NULL)
	{
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << '\n';
	}
	return texture;
}

int RenderWindow::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode; 
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

void RenderWindow::render(Entity& entity)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.h = 32;
	src.w = 32;
	SDL_Rect dst;
	dst.x = entity.getPos().x;
	dst.y = entity.getPos().y;
	dst.h = entity.getSize().h;
	dst.w = entity.getSize().w;
	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);	
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}
