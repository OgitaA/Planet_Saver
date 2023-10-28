#include"Game.hpp"

void Game::make_enemy_shot() {

	for (auto& e : enemy) {

		if (e.get_make_bullet() != -1) {

			double e_x = e.get_rect().x;
			double e_y = e.get_rect().y;
			double angle = 180;

			make_enemy_bullet(U"normal", e_x, e_y, 50, 1, 800, angle);

			e.set_make_bullet_done();
		}
	}
}

void Game::make_enemy_bullet(String _name, double _x, double _y, double _r, int _power, double _speed,double _angle) {

	double angle = ToRadians(_angle);

	enemy_bullet.push_back(Enemy_Bullet(_name, _x, _y, _r, _power, _speed,angle));
}
