#include"Game.hpp"

void Game::make_enemy_shot() {

	for (auto& e : enemy) {

		if (e.get_make_bullet() != -1) {

			int type = e.get_make_bullet();

			RectF e_r = e.get_rect();

			double e_x = e_r.x + e_r.w / 2;
			double e_y = e_r.y + e_r.h / 2;

			double angle = 180;

			if (type == 0) {

				angle = get_angle_e_to_p(e.get_rect());

				//Print << U"angle::" << angle;
			}
			else if (type == 1) {

				angle = 180;
			}

			

			make_enemy_bullet(U"normal", e_x, e_y, 1, 800, angle);

			e.set_make_bullet_done();
		}
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
