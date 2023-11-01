#include"Game.hpp"

void Game::draw() {

	if (main_scene == U"title") {
		draw_title();
	}
	else if (main_scene == U"stage_select") {
		draw_stage_select();
	}
	else if (main_scene == U"battle") {
		draw_battle();
	}
	else if (main_scene == U"gameover") {
		draw_battle();
		draw_gameover();
	}
	else if (main_scene == U"develop") {
		draw_develop();
	}

	draw_change_scene();
}
