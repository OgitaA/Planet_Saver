#include"Player_Bullet.hpp"

Player_Bullet::Player_Bullet(String _name, double _x, double _y, double _r, int _power, double _speed) {

	name = _name;

	circle = Circle(_x, _y, _r);

	speed = _speed;

	power = _power;

}

void Player_Bullet::update(double _d_time) {

	d_time = _d_time;

	move();
}

void Player_Bullet::draw() {

	TextureAsset(U"bullet").draw(circle.x - circle.r, circle.y - circle.r);
}

void Player_Bullet::move() {

	if (name == U"normal") {
		move_normal();
	}
}

void Player_Bullet::move_normal() {

	circle.x += speed * d_time;
}
