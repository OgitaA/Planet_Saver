#include"Enemy.hpp"

void Enemy::shot_eternal_move() {

	rect.x -= speed * d_time;


	if (move_scene == 0) {

		
		if (move_count > 2) {

			plus_make_bullet(17);

			move_v_0++;

			move_count = 0;
		}

		if (move_v_0 >= 2) {
			move_scene++;
		}
	}


}




void Enemy::boss_3_move() {

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

				

				if (move_v_1 == 0) {
					plus_make_bullet(21);
				}
				else if (move_v_1 == 1) {
					plus_make_bullet(22);
				}

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

	
				if (move_v_1 == 0) {
					plus_make_bullet(21);
				}
				else if (move_v_1 == 1) {
					plus_make_bullet(22);
				}

				move_v_0++;

				move_count = 0;
			}

			if (move_count_b > 0.5) {

				plus_make_enemy(5);

				/*
				if (move_v_1 == 0) {
					plus_make_enemy(4);
				}
				else if (move_v_1 == 1) {
					plus_make_enemy(6);
				}
				*/

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

void Enemy::bomb_g_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 1.5) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(1000);
			next_scene();
		}
	}

}

void Enemy::bomb_g_2_move() {



	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 2) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(1000);
			next_scene();
		}
	}

}

void Enemy::bomb_g_3_move() {



	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (move_count > 2.5) {
			next_scene();
		}
	}
	else if (move_scene == 1) {

		if (move_count > 0.5) {

			plus_make_bullet(1000);
			next_scene();
		}
	}


}


void Enemy::support_g_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1700) {

			plus_make_bullet(18);

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed * d_time;
	}

}

void Enemy::support_g_2_move() {

	if (move_scene == 0) {

		rect.x -= speed * d_time;

		if (rect.x < 1500) {

			plus_make_bullet(19);

			next_scene();
		}
	}
	else if (move_scene == 1) {

		rect.x -= speed * d_time;

		if (rect.x < 100) {

			plus_make_bullet(19);

			next_scene();
		}
	}
	else if (move_scene == 2) {

		rect.x -= speed * d_time;


	}

}


void Enemy::shot_g_straight_three_move() {

	rect.x -= speed * d_time;

	if (move_scene == 0) {

		if (move_count >= 2) {
			plus_make_bullet(30);

			move_count = 0;
			move_scene++;
		}
	}
}
