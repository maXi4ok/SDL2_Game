#include "Bullet.hpp"

void Bullet::update(float step, bool isColliding, const Wall &collider)
{
	if (isColliding)
	{
		xOffset = -xOffset;
		speed = -speed;
		setPos(getPos().x + xOffset, getPos().y + step * speed);
	}
	if ((getPos().y >= 500 - getSize().h && speed > 0) || (getPos().y <= 0 && speed < 0))
	{
		speed = -speed;
	}
	else if ((getPos().x >= 500 - getSize().w && xOffset > 0) || (getPos().x <= 0 && xOffset < 0))
	{
		xOffset = -xOffset;
	}
	setPos(getPos().x + xOffset, getPos().y + step * speed);
}