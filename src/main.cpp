#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Bullet.hpp"

float hireTimeInSeconds() {
	float t = SDL_GetTicks();
	t *= 0.001f;
	return t;
};

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_Init failed. Error: " << SDL_GetError() << '\n';
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cout << "IMG_Init failed. Error: " << IMG_GetError() << '\n';
	}

	RenderWindow window("Title Lol", 500, 500);

	SDL_Texture *BallTexture = window.loadTexture("..\\..\\res\\gfx\\Ball.png");
	SDL_Texture *BulletTexture = window.loadTexture("..\\..\\res\\gfx\\Bullet.png");

	std::vector<Bullet> entities = {
		Bullet(Vec2(50, 400), BulletTexture),
		Bullet(Vec2(100, 400), BulletTexture),
		Bullet(Vec2(150, 400), BulletTexture),
	};

	bool gameRunning = true;
	SDL_Event event;

	float lastTime = hireTimeInSeconds();

	while (gameRunning)
	{
		int startTicks = SDL_GetTicks();

		float newTime = hireTimeInSeconds();
		float deltaTime = newTime - lastTime;

		lastTime = newTime;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			default:
				break;
			}
		}

		window.clear();
		for (Bullet &e : entities)
		{
			e.update(deltaTime);
			window.render(e);
		}
		window.display();

		int frameTicks = startTicks - SDL_GetTicks();
		if (frameTicks < 1000 / window.getRefreshRate())
		{
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
		}
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}