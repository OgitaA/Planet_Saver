#include"Game.hpp"

void Game::make_player_shot() {

	double p_x = player.get_rect().x;
	double p_y = player.get_rect().y;

	int p_power = player.get_burn_gauge();

	double cool_time = player.get_shot_cool_time();



	if (cool_time <= 0) {

		if (p_power == 0) {

			int r = 30;

			int shot_x = p_x + (119 + 1) + (r / 2);
			int shot_y = p_y + (69 / 2);
			int power = 10;
			int speed = 800;
			double angle = 0;

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle);

			player.set_shot_cool_time(0.3);

		}

		else if (p_power == 1) {

			int r = 30;

			int shot_x = p_x + 119 + 1 + (r / 2);
			int shot_y = p_y + 69 / 2;
			int power = 10;
			int speed = 800;
			double angle = 0;

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed,angle);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle + 20);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle - 20);

			player.set_shot_cool_time(0.3);

		}

		else if (p_power == 2) {

			int r = 30;

			int shot_x = p_x + 119 + 1 + (r / 2);
			int shot_y = p_y + 69 / 2;
			int power = 10;
			int speed = 800;
			double angle = 0;

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle + 20);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle - 20);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle + 40);

			make_player_bullet(U"normal", shot_x, shot_y, r, power, speed, angle - 40);

			player.set_shot_cool_time(0.3);

		}

	}

}

void Game::make_player_bullet(String _name, double _x, double _y, double _r, int _power, double _speed,double _angle) {

	double angle = ToRadians(_angle);

	player_bullet.push_back(Player_Bullet(_name, _x, _y, _r, _power, _speed,angle));
}
