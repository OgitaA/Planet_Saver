#include"Enemy.hpp"


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

Enemy::Enemy(String _name, String _pattern, int _x, int _y, int _hp, int _score, String _item,double _maker_y) {

	name = _name;
	pattern = _pattern;
	rect.x = _x;
	rect.y = _y;
	hp = _hp;
	score = _score;
	item = _item;

	start_x = _x;
	start_y = _y;

	maker_y = _maker_y;

	each();

}

void Enemy::each() {

	//形と当たり判定

	circle = Circle(0, 0, 0);

	if (name == U"garbage_can") {

		speed = 230;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;
	}
	else if (name == U"garbage_can_elite") {

		speed = 230;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;
	}
	else if (name == U"rumba") {
		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_elite") {
		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_big") {
		speed = 250;
		rect.w = 150;
		rect.h = 150;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 75;
	}
	else if (name == U"dustpan") {

		speed = 300;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;
	}
	else if (name == U"rumba_green") {

		speed = 250;
		rect.w = 300;
		rect.h = 300;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 150;

		boss = true;
	}
	else if (name == U"rumba_red") {

		speed = 250;
		rect.w = 300;
		rect.h = 300;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 150;

		boss = true;
	}
	else if (name == U"rumba_black") {

		speed = 250;
		rect.w = 300;
		rect.h = 300;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 150;

		boss = true;
	}
	else if (name == U"rumba_baby") {
		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_marine") {
		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_marine_elite") {
		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_marine_big") {
		speed = 250;
		rect.w = 150;
		rect.h = 150;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 75;
	}
	else if (name == U"maker") {

		speed = 150;
		rect.w = 200;
		rect.h = 200;
		shape = U"Rect";
	}
	else if (name == U"rumba_track") {
		speed = 500;
		speed_2 = 800;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_bomb") {
		speed = 600;
		speed_2 = 800;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_neo") {

		speed = 250;
		rect.w = 150;
		rect.h = 150;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 75;
	}
	else if (name == U"rumba_support") {

		speed = 300;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"rumba_support_2") {

		speed = 500;
		rect.w = 100;
		rect.h = 100;
		shape = U"Circle";
		circle.x = 0;
		circle.y = 0;
		circle.r = 50;
	}
	else if (name == U"hard") {

		speed = 300;
		rect.w = 100;
		rect.h = 100;
		shape = U"Rect";
	}


	//ボス用登場アーマー
	if (boss == true) {
		boss_armer = true;
	}


	//パターン

	if (pattern == U"fast") {

		speed = 600;
	}
	else if (pattern == U"shot_straight_fast") {

		speed = 600;
	}
	else if (pattern == U"curve") {

		move_v_0 = 120;
		move_v_1 = 300;
	}
	//生成パターン
	else if (pattern == U"up_left") {

		speed = 150;
		speed_2 = 400;
		speed_3 = 400;

		//位置調整
		rect.x -= rect.w / 2;
	}


	/*
	if (name == U"boss_1") {

		speed = 500;
		shape = U"Quad";
		quad = Quad({ 10,10 }, { 10,70 }, { 113,73 }, { 113,6 });
		rect.w = 120;
		rect.h = 80;

		boss = true;
	}
    */


	//爆発パターン
	if (rect.w == 150 && rect.h == 150) {
		explode_size = 2;
	}
	else if (rect.w == 200 && rect.h == 200) {
		explode_size = 3;
	}


	//位置調整
	rect.y -= rect.h / 2;
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
	move_count_b += d_time;

	move();

	//ボス系

	//マイエフェクト
	update_my_effect();

	//ボス撃破後は弾ださない
	if (boss_broken == true) {
		make_bullet.clear();
	}
	
}

void Enemy::draw() {

	String image_name = U"enemy_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);

	//rect.drawFrame(5, Palette::Red);

	for (auto& e : my_effect) {
		e.draw();
	}
	
}

void Enemy::move() {

	if (pattern == U"normal") {

		straight_move();
	}
	else if (pattern == U"curve") {

		curve_move();
	}
	else if (pattern == U"stop") {


	}
	else if (pattern == U"shot_straight") {

		shot_straight_move();
	}
	else if (pattern == U"shot_straight_fast") {

		shot_straight_fast_move();
	}
	else if (pattern == U"shot_straight_three") {

		shot_straight_three_move();
	}
	else if (pattern == U"shot_g_straight_three") {

		shot_g_straight_three_move();
	}
	else if (pattern==U"fast") {

		straight_move();
	}
	else if (pattern == U"boss_1") {

		boss_1_move();
	}
	else if (pattern == U"support") {

		support_move();
	}
	else if (pattern == U"support_2") {

		support_2_move();
	}
	else if (pattern == U"support_3") {

		support_3_move();
	}
	else if (pattern == U"support_g") {

		support_g_move();
	}
	else if (pattern == U"support_g_2") {

		support_g_2_move();
	}
	else if (pattern == U"up_left") {

		up_left_move();
	}
	else if (pattern == U"maker") {

		maker_move();
	}

	else if (pattern == U"slow_shot_three") {

		slow_shot_three_move();
	}

	else if (pattern == U"track") {
		track_move();
	}

	else if (pattern == U"bomb") {
		bomb_move();
	}
	else if (pattern == U"bomb_2") {
		bomb_2_move();
	}
	else if (pattern == U"bomb_3") {
		bomb_3_move();
	}
	else if (pattern == U"bomb_g") {
		bomb_g_move();
	}
	else if (pattern == U"bomb_g_2") {
		bomb_g_2_move();
	}
	else if (pattern == U"bomb_g_3") {
		bomb_g_3_move();
	}


	else if (pattern == U"neo") {

		shot_eternal_move();
	}

	else if (pattern == U"boss_2") {

		boss_2_move();
	}
	else if (pattern == U"boss_3") {

		boss_3_move();
	}
}




void Enemy::next_scene() {

	move_count = 0;
	move_count_b = 0;
	
	move_scene_b = 0;

	move_scene++;
}

void Enemy::next_scene_b() {

	move_count = 0;
	move_count_b = 0;

	move_scene_b++;
}

void Enemy::change_move_scene(int v) {

	move_count = 0;
	move_count_b = 0;

	move_scene_b = 0;

	move_scene=v;
}

Quad Enemy::get_quad() {

	Quad quad_v({ rect.x + quad.p0.x, rect.y + quad.p0.y }, { rect.x + quad.p1.x, rect.y + quad.p1.y }, { rect.x + quad.p2.x, rect.y + quad.p2.y }, { rect.x + quad.p3.x, rect.y + quad.p3.y });

	return quad_v;

}

Circle Enemy::get_circle() {

	Circle circle_v(rect.x + circle.r, rect.y + circle.r, circle.r);

	return circle_v;
}

void Enemy::damage(int v) {

	hp -= v; if (hp < 0) { hp = 0; }

	white_count = 1;
}

void Enemy::update_my_effect() {

	if (boss_broken == true) {

		boss_broken_count += d_time;

		if (boss_broken_count > 0.3) {

			for (int i = 0; i < 5; i++) {

				int mini_x = rect.x + rect.w / 2;
				int mini_y = rect.y + rect.h / 2;

				bool random_x_plus_minus = 0;

				random_x_plus_minus = Random(1);

				int random_x_v = Random(rect.w / 2);

				if (random_x_plus_minus == 0) {
					mini_x -= random_x_v;
				}
				else if (random_x_plus_minus == 1) {
					mini_x += random_x_v;
				}


				bool random_y_plus_minus = 0;

				random_y_plus_minus = Random(1);

				int random_y_v = Random(rect.h/2);

				if (random_y_plus_minus == 0) {
					mini_y -= random_y_v;
				}
				else if (random_y_plus_minus == 1) {
					mini_y += random_y_v;
				}


				my_effect.push_back(My_Effect(U"middle_explode", mini_x, mini_y));


			}

			boss_broken_count = 0;
		}


		for (auto& e : my_effect) {
			e.update(d_time);
		}

		my_effect.remove_if([&](My_Effect e) {

			if (e.get_delete() == true) {
				return true;
			}

		return false;


		});

	}

}
