#pragma once
#include <iostream>

struct Vec2
{
	float x, y;

	Vec2() : x(0.0f), y(0.0f) {};
	Vec2(float x, float y) : x(x), y(y) {}

	void print()
	{
		std::cout << x << ", " << y << ";";
	}
};

struct textureSize
{
	float h, w;
	
	textureSize() : h(32), w(32) {};
	textureSize(int h, int w) : h(h), w(w) {};
};
