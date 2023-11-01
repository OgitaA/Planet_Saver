#include"Enemy.hpp"

Enemy::Enemy(String _name, double _x, double _y) {

	name = _name;
	rect.x = _x;
	rect.y = _y;

	start_x = _x;
	start_y = _y;

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

	start_x = _x;
	start_y = _y;


	each();

}

void Enemy::each() {

	if (name == U"normal") {

		speed = 300;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;
	}
	else if (name == U"elite") {

		speed = 300;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;
	}

	if (pattern == U"curve") {
		move_v_0 = 150;
		move_v_1 = 300;
	}

}

void Enemy::update(double _d_time) {

	d_time = _d_time;

	count += d_time;

	//shader
	if (white_count > 0) {
		white_count -= _d_time * 2;

		if (white_count < 0) {
			white_count = 0;
		}
	}

	//Move

	move_count += d_time;

	move();

	

	
}

void Enemy::draw() {

	String image_name = U"enemy_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);

	//rect.drawFrame(5, Palette::Red);
}

void Enemy::move() {

	if (pattern == U"normal") {

		straight_move();
	}
	else if (pattern == U"curve") {

		curve_move();
	}
}


void Enemy::straight_move() {

	rect.x -= speed * d_time;

	if (move_count >= 2) {
		make_bullet = 0;

		move_count = 0;
	}
}

void Enemy::curve_move() {

	move_angle += d_time * move_v_0;

	double sin_angle = move_angle * 3.14 / 180;

	rect.y = sin(sin_angle) * 200 + start_y;

	
	rect.x -= move_v_1 * d_time;

}


Quad Enemy::get_quad() {

	Quad quad_v({ rect.x + quad.p0.x, rect.y + quad.p0.y }, { rect.x + quad.p1.x, rect.y + quad.p1.y }, { rect.x + quad.p2.x, rect.y + quad.p2.y }, { rect.x + quad.p3.x, rect.y + quad.p3.y });

	return quad_v;

}

void Enemy::damage(int v) {

	hp -= v; if (hp < 0) { hp = 0; }

	white_count = 1;
}
