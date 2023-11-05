#include"Enemy.hpp"

void Enemy::curve_move() {

	move_angle += d_time * move_v_0;

	double sin_angle = move_angle * 3.14 / 180;

	rect.y = sin(sin_angle) * 100 + start_y;


	rect.x -= move_v_1 * d_time;

}

void Enemy::slow_shot_three_move() {

	rect.x -= speed * d_time;

	if (move_scene == 0) {

		if (move_count >= 2) {
			plus_make_bullet(10);

			move_count = 0;
			move_scene++;
		}
	}
}

void Enemy::track_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count >2) {

			next_scene();
		}
	}
	else if (move_scene == 1) {

		track_decide_angle = track_angle;

		next_scene();
	}
	else if (move_scene == 2) {

		//Print << U"angle::" << track_angle;
		//Print << U"d_angle::" << track_decide_angle;

		rect.x += cos(track_decide_angle) * speed_2 * d_time;
		rect.y += sin(track_decide_angle) * speed_2 * d_time;
	}

	
}

void Enemy::bomb_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 1.5) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(999);
			next_scene();
		}
	}

}

void Enemy::bomb_2_move() {

	

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 2) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(999);
			next_scene();
		}
	}

}

void Enemy::bomb_3_move() {

	

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 2.5) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(999);
			next_scene();
		}
	}


}

void Enemy::boss_2_move() {

	//登場
	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1920 - 350) {

			boss_armer = false;

			change_move_scene(2);
		}
	}
	//中央(とばし)
	else if (move_scene == 1) {

		//移動
		if (move_scene_b == 0) {

			rect.y -= speed * d_time;

			if (rect.y <= 100 + 100) {

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 1) {

			if (move_count > 1) {

				next_scene_b();
			}
		}
		//弾を撃つ
		else if (move_scene_b == 2) {

			if (move_count > 0.3) {

				plus_make_bullet(14);

				move_v_0++;

				move_count = 0;
			}

			if (move_count_b > 0.5) {


				plus_make_enemy(1);

				move_count_b = 0;
			}

			//
			if (move_v_0 == 3) {

				move_v_0 = 0;

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 3) {

			if (move_count > 1) {

				next_scene();
			}
		}
	}
	//上
	else if (move_scene == 2) {

		//移動
		if (move_scene_b == 0) {

			rect.y -= speed * d_time;

			if (rect.y <= 100 + 100) {

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 1) {

			if (move_count > 0.5) {

				next_scene_b();
			}
		}
		//弾を撃つ
		else if (move_scene_b == 2) {

			if (move_count > 0.3) {

				plus_make_bullet(14);

				move_v_0++;

				move_count = 0;
			}

			//仲間をよぶ

			if (move_count_b > 0.5) {

				plus_make_enemy(5);
				/*
				if (move_v_1 == 0) {
					
				}
				else if (move_v_1 == 1) {
					plus_make_enemy(7);
				}*/

				move_count_b = 0;
			}

			//
			if (move_v_0 == 3) {

				move_v_0 = 0;

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 3) {

			if (move_count > 0.5) {

				next_scene();
			}
		}
	}
	//下
	else if (move_scene == 3) {

		//移動
		if (move_scene_b == 0) {

			rect.y += speed * d_time;

			if (rect.y >= (1080 - 45 - rect.h - 100)) {

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 1) {

			if (move_count > 0.5) {

				next_scene_b();
			}
		}
		//弾を撃つ
		else if (move_scene_b == 2) {

			if (move_count > 0.3) {

				plus_make_bullet(14);

				move_v_0++;

				move_count = 0;
			}

			if (move_count_b > 0.5) {

				plus_make_enemy(4);

				/*
				if (move_v_1 == 0) {
					plus_make_enemy(4);
				}
				else if (move_v_1 == 1) {
					plus_make_enemy(6);
				}*/

				move_count_b = 0;
			}

			//
			if (move_v_0 == 3) {

				move_v_0 = 0;

				next_scene_b();
			}
		}
		//待機
		else if (move_scene_b == 3) {

			if (move_count > 0.5) {

				change_move_scene(2);




				if (move_v_1 == 0) {
					move_v_1 = 1;
				}
				else if (move_v_1 == 1) {
					move_v_1 = 0;
				}
			}
		}
	}

}


void Enemy::support_2_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1500) {

			plus_make_bullet(15);

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed * d_time;

		if (rect.x < 100) {

			plus_make_bullet(15);

			next_scene();
		}
	}
	else if (move_scene == 2) {

		rect.x -= speed * d_time;

		
	}

}

void Enemy::support_3_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1400) {

			plus_make_bullet(15);

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed * d_time;

		if (rect.x < 800) {

			plus_make_bullet(15);

			next_scene();
		}
	}
	else if (move_scene == 2) {

		rect.x -= speed * d_time;

		if (rect.x < 200) {

			plus_make_bullet(15);

			next_scene();
		}
	}
	else if (move_scene == 3) {

		rect.x -= speed * d_time;
	}

}
