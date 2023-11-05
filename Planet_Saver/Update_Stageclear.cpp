#include"Game.hpp"

void Game::update_stageclear() {

	if (KeyZ.down()) {
		change_scene_stage_select();

		//新ステージ解放
		if (clear_stage < stage) {
			clear_stage = stage;
		}
	}



}
