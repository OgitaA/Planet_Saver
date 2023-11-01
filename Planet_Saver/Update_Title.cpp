#include"Game.hpp"

void Game::update_title() {

	if (title_once == false) {

		play_bgm(0);

		title_once = true;
	}

	/*

	double d_time = Scene::DeltaTime();

	//キーインターバル
	const double cur_interval_v = 0.5;


	//キーインターバル減少
	if (title_cur_interval > 0) {
		title_cur_interval -= d_time;
	}

	//キーが押されていない（指から離れている）
	if (KeyUp.pressed() and KeyDown.pressed()) {
		title_cur_interval = 0;
	}

	//キーインターバルがない
	if (title_cur_interval <= 0) {

		if (KeyUp.pressed()) {

			title_cur--;

			title_cur_interval = cur_interval_v;
		}
		else if (KeyDown.pressed()) {

			title_cur++;

			title_cur_interval = cur_interval_v;
		}

	}

	if (title_cur <= -1) {
		title_cur = 2;
	}

	if (title_cur >= 3) {
		title_cur = 0;
	}

	if (KeyZ.down()) {

		switch (title_scene)
		{
		case 0://Start
			change_scene_battle();
			break;
		case 1://Option

			break;
		case 2://Exit
			System::Exit();
			break;
		default:
			break;
		}

	}
*/

	if (KeyZ.down()) {
		change_scene_stage_select();
	}
}
