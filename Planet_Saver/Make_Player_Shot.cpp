#include"Game.hpp"

void Game::make_player_shot() {

	if (player.get_miss() == false) {

		double p_x = player.get_rect().x;
		double p_y = player.get_rect().y;

		int p_power = player.get_burn_gauge();

		double cool_time = player.get_shot_cool_time();



		if (cool_time <= 0) {



			int r = 17;

			int shot_x = p_x + (119 + 1) + (r / 2);
			int shot_y = p_y + (69 / 2);
			int power = 10;
			int speed = 1500;
			double angle = 0;


			make_player_bullet(U"main", shot_x, shot_y, r, power, speed, angle);

			/*
			//パワー調整
			if (p_power == 1) {
				power = 8;
			}
			else if (p_power == 2) {
				power = 6;
			}
			else if (p_power == 3) {
				power = 5;
			}
			else if (p_power == 4) {
				power = 5;
			}
			else if (p_power == 5) {
				power = 5;
			}*/

			//オプションパワー
			power = 2;
			

			
			r = 17;

			for (size_t o = 0; o < player.get_option_size(); o++) {

				double x = player.get_option_pos()[o].x + 20;
				double y = player.get_option_pos()[o].y + 56 / 2 - 34 / 2 - 10;

				make_player_bullet(U"sub", x, y, r, power, speed, angle);
			}

			player.set_shot_cool_time(0.1);
		}
	}
}

void Game::make_player_bullet(String _name, double _x, double _y, double _r, int _power, double _speed,double _angle) {

	double angle = ToRadians(_angle);

	player_bullet.push_back(Player_Bullet(_name, _x, _y, _r, _power, _speed,angle));
}
