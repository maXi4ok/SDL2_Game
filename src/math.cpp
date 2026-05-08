#include "Math.hpp"
#include "Entity.hpp"

bool Math::checkCollision(Entity &a, Entity &b)
{
	float aLeft = a.getPos().x;
	float aRight = a.getPos().x + a.getSize().w;
	float aTop = a.getPos().y;
	float aBottom = a.getPos().y + a.getSize().h;

	float bLeft = b.getPos().x;
	float bRight = b.getPos().x + b.getSize().w;
	float bTop = b.getPos().y;
	float bBottom = b.getPos().y + b.getSize().h;

	if (aRight < bLeft || aLeft > bRight || aBottom < bTop || aTop > bBottom)
	{
		return false;
	}
	return true;
}