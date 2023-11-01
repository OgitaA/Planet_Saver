#include"Game.hpp"

void Game::update() {

	//SE関係
	update_se_main(Scene::DeltaTime());

	if (change_scene_process == false) {

		if (main_scene == U"title") {
			update_title();
		}
		else if (main_scene == U"stage_select") {
			update_stage_select();
		}
		else if (main_scene == U"battle") {
			update_battle();
		}
		else if (main_scene == U"gameover") {
			update_gameover();
		}
		else if (main_scene == U"develop") {
			update_develop();
		}
	}
	else if (change_scene_process == true) {

		update_change_scene();
	}

	//SEを実際にならす
	play_se_main();


}
