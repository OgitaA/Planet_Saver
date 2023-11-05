#include"Enemy.hpp"

void Enemy::straight_move() {

	rect.x -= speed * d_time;


}

void Enemy::shot_straight_move() {

	rect.x -= speed * d_time;

	if (move_scene == 0) {

		if (move_count >= 1) {
			plus_make_bullet(0);

			move_count = 0;
			move_scene++;
		}
	}
}

void Enemy::shot_straight_fast_move() {

	rect.x -= speed * d_time;

	if (move_scene == 0) {

		if (move_count >= 0.7) {
			plus_make_bullet(0);

			move_count = 0;
			move_scene++;
		}
	}
}

void Enemy::shot_straight_three_move() {

	rect.x -= speed * d_time;

	if (move_scene == 0) {

		if (move_count >= 2) {
			plus_make_bullet(1);

			move_count = 0;
			move_scene++;
		}
	}
}



void Enemy::up_left_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		rect.y -= speed_2 * d_time;

		if (rect.y <= maker_y - 400) {

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed_3 * d_time;

		if (move_count > 1.5) {

			//plus_make_bullet(0);
			next_scene();
		}
	}
	else if (move_scene == 2) {
		rect.x -= speed_3 * d_time;
	}
}

void Enemy::maker_move() {

	rect.x -= speed * d_time;

	//待機
	if (move_scene == 0) {

		if (move_count > 1) {

			next_scene();
		}
	}
	//起動
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_enemy(0);

			move_v_0++;

			move_count = 0;
		}

		if (move_v_0 == 3) {
			
			move_count = 0;

			move_v_0 = 0;

			move_scene = 0;
		}
	}

}

void Enemy::support_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1700) {

			plus_make_bullet(13);

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed * d_time;
	}

}

void Enemy::boss_1_move() {

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

				plus_make_bullet(12);

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

				plus_make_bullet(12);

				move_v_0++;

				move_count = 0;
			}

			//仲間をよぶ

			if (move_count_b > 0.5) {

				plus_make_enemy(2);

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

				plus_make_bullet(12);

				move_v_0++;

				move_count = 0;
			}

			if (move_count_b > 0.5) {


				plus_make_enemy(3);

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
			}
		}
	}

}
