#include"Game.hpp"

void Game::draw() {

	switch (main_scene)
	{
	case 0:
		draw_battle();
		break;
	case 1:
		draw_stage_select();
		break;
	case 2:
		//update_menu();
		break;
	case 100:
		draw_title();
		break;
	case 101:
		//update_setting();
		break;
	case 102:
		//update_ending();
		break;
	default:
		break;
	}


	draw_change_scene();
}
