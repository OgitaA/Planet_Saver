#include"Game.hpp"

void Game::update() {

	//SE関係
	update_se_main(Scene::DeltaTime());

	if (change_scene_process == false) {

		switch (main_scene)
		{
		case 0:
			update_battle();
			break;
		case 1:
			update_stage_select();
			break;
		case 2:
			//update_menu();
			break;
		case 100:
			update_title();
			break;
		case 101:
			//update_setting();
			break;
		case 102:
			//update_ending();
			break;
		case 999:
			update_develop();
			break;
		default:
			break;
		}

	}
	else if (change_scene_process == true) {

		update_change_scene();
	}

	//SEを実際にならす
	play_se_main();


}
