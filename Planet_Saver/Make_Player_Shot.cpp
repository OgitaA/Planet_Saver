#include"Game.hpp"

void Game::make_player_shot() {

	double p_x = player.get_rect().x;
	double p_y = player.get_rect().y;

	double cool_time = player.get_shot_cool_time();



	if (cool_time <= 0) {

		make_player_bullet(U"normal", p_x, p_y, 30, 1, 800);

		player.set_shot_cool_time(0.3);
	}

}

void Game::make_player_bullet(String _name, double _x, double _y, double _r, int _power, double _speed) {

	player_bullet.push_back(Player_Bullet(_name, _x, _y, _r, _power, _speed));
}
