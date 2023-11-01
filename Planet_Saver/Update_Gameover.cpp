#include"Game.hpp"

void Game::update_gameover() {

	if (gameover_once == false) {
		gameover_cur = 0;
		gameover_once = true;
	}

	if (KeyUp.down()) {
		gameover_cur--;
	}
	else if (KeyDown.down()) {
		gameover_cur++;
	}

	if (gameover_cur < 0) {
		gameover_cur = 1;
	}

	if (gameover_cur > 1) {
		gameover_cur = 0;
	}


	if (KeyZ.down()) {

		if (gameover_cur == 0) {

			change_scene_battle();		
		}
		else if(gameover_cur==1){

			change_scene_stage_select();
		}

		gameover_once = false;
		

	}
}
