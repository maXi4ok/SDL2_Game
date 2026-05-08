#include <iostream>
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Bullet.hpp"
#include "Wall.hpp"
#include "Math.hpp"

float hireTimeInSeconds()
{
	float t = SDL_GetTicks();
	t *= 0.001f;
	return t;
};

int main(int argc, char *argv[])
{
	srand(time(0));
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_Init failed. Error: " << SDL_GetError() << '\n';
		return 1;
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cout << "IMG_Init failed. Error: " << IMG_GetError() << '\n';
		return 1;
	}

	RenderWindow window("Title Lol", 500, 500);

	SDL_Texture *BallTexture = window.loadTexture("..\\..\\res\\gfx\\Ball.png");
	SDL_Texture *BulletTexture = window.loadTexture("..\\..\\res\\gfx\\Bullet.png");
	SDL_Texture *WallTexture = window.loadTexture("..\\..\\res\\gfx\\Wall.png");

	std::vector<Bullet> bullets = {
		Bullet(Vec2(50, 400), BallTexture),
		Bullet(Vec2(150, 400), BallTexture),
		Bullet(Vec2(250, 400), BallTexture),
		Bullet(Vec2(350, 400), BallTexture),
		Bullet(Vec2(450, 400), BallTexture),
	};

	std::vector<Wall> walls = {};
	for (size_t i = 0; i < 10; i++)
	{
		walls.push_back(Wall(Vec2((rand() % 450), (rand() % 450)), WallTexture));
	}
	

	bool gameRunning = true;
	SDL_Event event;

	const float timeStep = 0.01f;
	float lastTime = hireTimeInSeconds();
	float accumulator = 0.0f;

	while (gameRunning)
	{
		float currentTime = hireTimeInSeconds();
		float frameTime = currentTime - lastTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		lastTime = currentTime;
		accumulator += frameTime;

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

		while (accumulator >= timeStep)
		{
			for (Bullet &b : bullets)
			{
				Wall* collider = nullptr;

				for (Wall &w : walls)
				{
					if (Math::checkCollision(b, w))
					{
						collider = &w;
						break;
					}
				}

				b.update(timeStep, collider != nullptr, *collider);
			}

			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();
		for (Bullet &b : bullets)
		{
			window.render(b);
		}
		for (Wall &w : walls)
		{
			window.render(w);
		}
		window.display();
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}