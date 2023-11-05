#include"Game.hpp"

void Game::make_enemy_shot() {

	if (stage_clear_flag == false) {

		for (auto& e : enemy) {

			if (e.get_make_bullet().size() >= 1) {

				for (size_t b = 0; b < e.get_make_bullet().size(); b++) {

					int type = e.get_make_bullet()[b];

					RectF e_r = e.get_rect();

					double e_x = e_r.x + e_r.w / 2;
					double e_y = e_r.y + e_r.h / 2;

					double angle = 180;


					//各種ショットの設定
					if (type == 0) {

						angle = get_angle_e_to_p(e.get_rect());

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);



					}
					else if (type == 1) {

						angle = 180;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 - 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 + 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);
					}
					else if (type == 2) {

						angle = 180;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 - 10;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 + 10;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 - 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = 180 + 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);
					}
					else if (type == 3) {

						angle = get_angle_e_to_p(e.get_rect());

						make_enemy_bullet(U"big", e_x, e_y, 1, 800, angle);
					}
					else if (type == 10) {

						angle = 180;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);

						angle = 180 - 10;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);

						angle = 180 + 10;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);

						angle = 180 - 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);

						angle = 180 + 20;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);
					}
					else if (type == 11) {

						/*
						angle = 180;

						make_enemy_bullet(U"green", e_x, e_y, 1, 600, angle);

						angle = 180 - 10;

						make_enemy_bullet(U"green", e_x, e_y, 1, 600, angle);

						angle = 180 + 10;

						make_enemy_bullet(U"green", e_x, e_y, 1, 600, angle);
						*/

						double e_p = get_angle_e_to_p(e.get_rect());

						angle = e_p;

						make_enemy_bullet(U"green", e_x, e_y, 1, 350, angle);

						angle = e_p - 25;

						make_enemy_bullet(U"green", e_x, e_y, 1, 350, angle);

						angle = e_p + 25;

						make_enemy_bullet(U"green", e_x, e_y, 1, 350, angle);

					}
					//ボス１
					else if (type == 12) {



						double e_p = get_angle_e_to_p(e.get_rect());

						angle = e_p;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p - 15;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p + 15;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p - 30;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p + 30;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

					}
					else if (type == 13) {

						double e_p = get_angle_e_to_p(e.get_rect());

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, e_p);

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, e_p-15);

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, e_p + 15);

					}
					//ボス2
					else if (type == 14) {

						/*
						double v = 0;

						double e_p = get_angle_e_to_p(e.get_rect());

						double fragment = 360 / 12;

						for (int c = 0; c < 12; c++) {

							v = e_p + fragment * c;

							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, v);
						}*/


						double e_p = get_angle_e_to_p(e.get_rect());

						int v_1 = e_p;
						int v_2 = e_p + 10;
						int v_3 = e_p + 20;
						int v_4 = e_p - 10;
						int v_5 = e_p - 20;
						int v_6 = e_p + 15;
						int v_7 = e_p - 15;
						int v_8 = e_p + 25;
						int v_9 = e_p - 25;

						int v = 0;

						for (int i = 0; i < 4; i++) {

							int a = v_2 + 90 * i;
							int b = v_3 + 90 * i;
							int c = v_4 + 90 * i;
							int d = v_5 + 90 * i;
							int e = v_6 + 90 * i;
							int f = v_7 + 90 * i;
							int g = v_8 + 90 * i;
							int h = v_9 + 90 * i;

							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, a);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, b);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, c);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, d);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, e);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, f);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, g);
							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, h);
						}


					}
					else if (type == 15) {

						double v = 0;

						double e_p = get_angle_e_to_p(e.get_rect());

						double fragment = 360 / 16;

						for (int c = 0; c < 16; c++) {

							v = fragment * c;

							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, v);
						}
					}
					//ボス3
					else if (type == 16) {



						double e_p = get_angle_e_to_p(e.get_rect());

						angle = e_p;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p - 15;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p + 15;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p - 30;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

						angle = e_p + 30;

						make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

					}
					else if (type == 17) {

						angle = 180;

						make_enemy_bullet(U"green", e_x, e_y, 1, 500, angle);

						angle = 180 - 10;

						make_enemy_bullet(U"green", e_x, e_y, 1, 500, angle);

						angle = 180 + 10;

						make_enemy_bullet(U"green", e_x, e_y, 1, 500, angle);

						angle = 180 - 20;

						make_enemy_bullet(U"green", e_x, e_y, 1, 500, angle);

						angle = 180 + 20;

						make_enemy_bullet(U"green", e_x, e_y, 1, 500, angle);
					}
					else if (type == 18) {

						double e_p = get_angle_e_to_p(e.get_rect());

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, e_p);

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, e_p - 15);

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, e_p + 15);

					}
					else if (type == 19) {

						double v = 0;

						double e_p = get_angle_e_to_p(e.get_rect());

						double fragment = 360 / 16;

						for (int c = 0; c < 16; c++) {

							v = fragment * c;

							make_enemy_bullet(U"green", e_x, e_y, 1, 400, v);
						}
					}
					else if (type == 20) {

						angle = 180;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = 180 - 20;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = 180 + 20;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);
					}
					//ボス３new
					else if (type == 21) {



						double e_p = get_angle_e_to_p(e.get_rect());

						angle = e_p;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = e_p - 15;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = e_p + 15;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = e_p - 30;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

						angle = e_p + 30;

						make_enemy_bullet(U"green", e_x, e_y, 1, 800, angle);

					}
					else if (type == 22) {

						/*
						double v = 0;

						double e_p = get_angle_e_to_p(e.get_rect());

						double fragment = 360 / 12;

						for (int c = 0; c < 12; c++) {

							v = e_p + fragment * c;

							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, v);
						}*/


						double e_p = get_angle_e_to_p(e.get_rect());

						int v_1 = e_p;
						int v_2 = e_p + 10;
						int v_3 = e_p + 20;
						int v_4 = e_p - 10;
						int v_5 = e_p - 20;
						int v_6 = e_p + 15;
						int v_7 = e_p - 15;
						int v_8 = e_p + 25;
						int v_9 = e_p - 25;

						int v = 0;

						for (int i = 0; i < 4; i++) {

							int a = v_2 + 90 * i;
							int b = v_3 + 90 * i;
							int c = v_4 + 90 * i;
							int d = v_5 + 90 * i;
							int e = v_6 + 90 * i;
							int f = v_7 + 90 * i;
							int g = v_8 + 90 * i;
							int h = v_9 + 90 * i;

							make_enemy_bullet(U"green", e_x, e_y, 1, 400, a);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, b);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, c);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, d);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, e);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, f);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, g);
							make_enemy_bullet(U"green", e_x, e_y, 1, 400, h);
						}


					}

					//自爆
					else if (type == 999) {

						int fragment = 360 / 8;

						for (int c = 0; c < 8; c++) {

							angle += fragment * c;

							make_enemy_bullet(U"normal", e_x, e_y, 1, 400, angle);
						}

						e.set_bomb_death();
					}
					//自爆・緑
					else if (type == 1000) {

						int fragment = 360 / 8;

						for (int c = 0; c < 8; c++) {

							angle += fragment * c;

							make_enemy_bullet(U"green", e_x, e_y, 1, 400, angle);
						}

						e.set_bomb_death();
					}



				}

				e.set_make_bullet_done();
			}
		}


		//自爆系
		enemy.remove_if([&](Enemy e) {

			if (e.get_bomb_death() == true) {

				double center_x = e.get_center_x();
				double center_y = e.get_center_y();

				my_effect.push_back(My_Effect(U"explode", center_x, center_y));

				return true;
			}
			else {

				return false;
			}

			});

	}
}

void Game::make_enemy_bullet(String _name, double _x, double _y,int _power, double _speed,double _angle) {

	double angle = ToRadians(_angle);

	enemy_bullet.push_back(Enemy_Bullet(_name, _x, _y,_power, _speed,angle));
}

double Game::get_angle_e_to_p(RectF e_rect) {

	RectF p = player.get_rect();

	double p_x = p.x + p.w / 2;
	double p_y = p.y + p.h / 2;

	RectF e = e_rect;

	double e_x = e.x + e.w / 2;
	double e_y = e.y + e.h / 2;

	return atan2(p_y - e_y, p_x - e_x) * 180 / 3.14;
}
