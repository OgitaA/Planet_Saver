#include"Game.hpp"

void Game::update_stage_select() {

	double d_time = Scene::DeltaTime();

	//キーインターバル
	const double stage_select_cur_interval_v = 0.5;


	//キーインターバル減少
	if (stage_select_cur_interval > 0) {
		stage_select_cur_interval -= d_time;
	}

	//キーが押されていない（指から離れている）
	if (!KeyUp.pressed() and !KeyDown.pressed()) {
		stage_select_cur_interval = 0;
	}

	//キーインターバルがない
	if (stage_select_cur_interval <= 0) {

		if (KeyUp.pressed()) {

			stage_select_cur--;

			stage_select_cur_interval = stage_select_cur_interval_v;
		}
		else if (KeyDown.pressed()) {

			stage_select_cur++;

			stage_select_cur_interval = stage_select_cur_interval_v;
		}

	}

	if (stage_select_cur <= -1) {
		stage_select_cur = 2;
	}

	if (stage_select_cur >= 3) {
		stage_select_cur = 0;
	}



	if (KeyZ.down()) {

		change_scene_battle();

		stage = stage_select_cur + 1;

		make_stage(stage);
	}
	else if (KeyX.down()) {

		change_scene_title();
	}

}
