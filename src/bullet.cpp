#include "Bullet.hpp" 

void Bullet::update (float deltaTime) {
	setPos(getPos().x, getPos().y + getPos().y * deltaTime * -0.1f);
}