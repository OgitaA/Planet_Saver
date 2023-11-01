#include"Enemy_Bullet.hpp"

Enemy_Bullet::Enemy_Bullet(String _name, double _x, double _y,int _power, double _speed,double _angle) {

	name = _name;

	circle.x = _x;
	circle.y = _y;

	speed = _speed;

	power = _power;

	angle = _angle;

	set_up();
}

void Enemy_Bullet::set_up() {

	if (name = U"normal") {
		circle.r = 46 / 2;
	}

}

void Enemy_Bullet::update(double _d_time) {

	d_time = _d_time;

	move();
}

void Enemy_Bullet::draw() {

	String image = U"enemy_bullet_" + name;

	TextureAsset(image).draw(circle.x - circle.r, circle.y - circle.r);

	//circle.drawFrame(5, Palette::Red);
}

void Enemy_Bullet::move() {

	if (name == U"normal") {
		move_normal();
	}
}

void Enemy_Bullet::move_normal() {

	circle.x += cos(angle) * speed * d_time;
	circle.y += sin(angle) * speed * d_time;
}
