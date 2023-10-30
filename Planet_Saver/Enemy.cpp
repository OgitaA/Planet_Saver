#include"Enemy.hpp"

Enemy::Enemy(String _name, double _x, double _y) {

	name = _name;
	rect.x = _x;
	rect.y = _y;

	each();

}

Enemy::Enemy(String _name, String _pattern, int _x, int _y, int _hp, int _score, String _item) {

	name = _name;
	pattern = _pattern;
	rect.x = _x;
	rect.y = _y;
	hp = _hp;
	score = _score;
	item = _item;

	each();

}

void Enemy::each() {

	if (pattern == U"normal") {
		speed = 200;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
	}
}

void Enemy::update(double _d_time) {

	d_time = _d_time;

	count += d_time;

	move();

}

void Enemy::draw() {

	String image_name = U"enemy_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);
}

void Enemy::move() {

	if (pattern == U"normal") {

		straight_move();
	}
}


void Enemy::straight_move() {

	rect.x -= speed * d_time;
}


Quad Enemy::get_quad() {

	Quad quad_v({ rect.x + quad.p0.x, rect.y + quad.p0.y }, { rect.x + quad.p1.x, rect.y + quad.p1.y }, { rect.x + quad.p2.x, rect.y + quad.p2.y }, { rect.x + quad.p3.x, rect.y + quad.p3.y });

	return quad_v;

}
