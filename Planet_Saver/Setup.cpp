﻿#include"Game.hpp"

void Game::set_up() {

	set_screen();
	set_data();
	load_image();
	load_music();
	load_font();
	set_shader();

	set_up_develop();
	debug_data();
}

void Game::set_screen() {
	//フルスクリーン
	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);
}

void Game::set_data() {

	set_stage_select_box();


}

void Game::set_stage_select_box() {

	make_stage_select_box(1, U"すくえ！都市ゴミ！！");
	make_stage_select_box(2, U"すくえ！海洋ゴミ！！");
	make_stage_select_box(3, U"すくえ！産業ゴミ！！");
}

void Game::make_stage_select_box(int v, String name) {

	stage_select_box.push_back(Stage_Select_Box(v, name));
}

void Game::load_image() {

	//Change_Scene
	TextureAsset::Register(U"black", U"image/change_scene/black.png");
	TextureAsset::Load(U"black");


	//Title
	TextureAsset::Register(U"title_back", U"image/title/back.png");
	TextureAsset::Load(U"title_back");

	//back
	TextureAsset::Register(U"back_1", U"image/battle/back/1.png");
	TextureAsset::Load(U"back_1");

	TextureAsset::Register(U"back_2", U"image/battle/back/2.png");
	TextureAsset::Load(U"back_2");

	TextureAsset::Register(U"back_3", U"image/battle/back/3.png");
	TextureAsset::Load(U"back_3");

	//BackObject
	TextureAsset::Register(U"back_object_crowd", U"image/battle/back/back_object/crowd.png");
	TextureAsset::Load(U"back_object_crowd");

	TextureAsset::Register(U"back_object_crowd_2", U"image/battle/back/back_object/crowd_2.png");
	TextureAsset::Load(U"back_object_crowd_2");


	TextureAsset::Register(U"back_object_bill", U"image/battle/back/back_object/bill.png");
	TextureAsset::Load(U"back_object_bill");

	TextureAsset::Register(U"back_object_bill_2", U"image/battle/back/back_object/bill_2.png");
	TextureAsset::Load(U"back_object_bill_2");

	TextureAsset::Register(U"back_object_bill_3", U"image/battle/back/back_object/bill_3.png");
	TextureAsset::Load(U"back_object_bill_3");

	TextureAsset::Register(U"back_object_bill_4", U"image/battle/back/back_object/bill_4.png");
	TextureAsset::Load(U"back_object_bill_4");

	TextureAsset::Register(U"back_object_bill_5", U"image/battle/back/back_object/bill_5.png");
	TextureAsset::Load(U"back_object_bill_5");

	TextureAsset::Register(U"back_object_bill_6", U"image/battle/back/back_object/bill_6.png");
	TextureAsset::Load(U"back_object_bill_6");

	TextureAsset::Register(U"back_object_tree_big", U"image/battle/back/back_object/tree_big.png");
	TextureAsset::Load(U"back_object_tree_big");

	TextureAsset::Register(U"back_object_tree_small", U"image/battle/back/back_object/tree_small.png");
	TextureAsset::Load(U"back_object_tree_small");

	TextureAsset::Register(U"back_object_bubble", U"image/battle/back/back_object/bubble.png");
	TextureAsset::Load(U"back_object_bubble");

	TextureAsset::Register(U"back_object_fish_1", U"image/battle/back/back_object/fish_1.png");
	TextureAsset::Load(U"back_object_fish_1");

	TextureAsset::Register(U"back_object_fish_2", U"image/battle/back/back_object/fish_2.png");
	TextureAsset::Load(U"back_object_fish_2");

	TextureAsset::Register(U"back_object_stone_1", U"image/battle/back/back_object/stone_1.png");
	TextureAsset::Load(U"back_object_stone_1");

	TextureAsset::Register(U"back_object_stone_2", U"image/battle/back/back_object/stone_2.png");
	TextureAsset::Load(U"back_object_stone_2");

	TextureAsset::Register(U"back_object_stone_3", U"image/battle/back/back_object/stone_3.png");
	TextureAsset::Load(U"back_object_stone_3");

	TextureAsset::Register(U"back_object_stone_4", U"image/battle/back/back_object/stone_4.png");
	TextureAsset::Load(U"back_object_stone_4");

	TextureAsset::Register(U"back_object_stone_5", U"image/battle/back/back_object/stone_5.png");
	TextureAsset::Load(U"back_object_stone_5");

	TextureAsset::Register(U"back_object_stone_6", U"image/battle/back/back_object/stone_6.png");
	TextureAsset::Load(U"back_object_stone_6");

	TextureAsset::Register(U"back_object_coral_1", U"image/battle/back/back_object/coral_1.png");
	TextureAsset::Load(U"back_object_coral_1");

	TextureAsset::Register(U"back_object_coral_2", U"image/battle/back/back_object/coral_2.png");
	TextureAsset::Load(U"back_object_coral_2");

	TextureAsset::Register(U"back_object_factory_1", U"image/battle/back/back_object/factory_1.png");
	TextureAsset::Load(U"back_object_factory_1");

	TextureAsset::Register(U"back_object_factory_2", U"image/battle/back/back_object/factory_2.png");
	TextureAsset::Load(U"back_object_factory_2");

	TextureAsset::Register(U"back_object_factory_3", U"image/battle/back/back_object/factory_3.png");
	TextureAsset::Load(U"back_object_factory_3");

	TextureAsset::Register(U"back_object_factory_4", U"image/battle/back/back_object/factory_4.png");
	TextureAsset::Load(U"back_object_factory_4");

	//player
	TextureAsset::Register(U"player", U"image/battle/object/player/player.png");
	TextureAsset::Load(U"player");

	TextureAsset::Register(U"player_white", U"image/battle/object/player/player_white.png");
	TextureAsset::Load(U"player_white");

	TextureAsset::Register(U"barrier", U"image/battle/object/player/barrier.png");
	TextureAsset::Load(U"barrier");

	TextureAsset::Register(U"barrier_damage", U"image/battle/object/player/barrier_damage.png");
	TextureAsset::Load(U"barrier_damage");

	//player
	TextureAsset::Register(U"player_burn", U"image/battle/object/player/player_burn.png");
	TextureAsset::Load(U"player_burn");

	TextureAsset::Register(U"player_non_burn", U"image/battle/object/player/player_non_burn.png");
	TextureAsset::Load(U"player_non_burn");

	TextureAsset::Register(U"player_recycle", U"image/battle/object/player/player_recycle.png");
	TextureAsset::Load(U"player_recycle");

	TextureAsset::Register(U"player_error", U"image/battle/object/player/player_error.png");
	TextureAsset::Load(U"player_error");

	TextureAsset::Register(U"net", U"image/battle/object/player/net.png");
	TextureAsset::Load(U"net");


	TextureAsset::Register(U"player_option", U"image/battle/object/player/player_option.png");
	TextureAsset::Load(U"player_option");


	TextureAsset::Register(U"net_burn", U"image/battle/object/player/net_burn.png");
	TextureAsset::Load(U"net_burn");

	TextureAsset::Register(U"net_non_burn", U"image/battle/object/player/net_non_burn.png");
	TextureAsset::Load(U"net_non_burn");

	TextureAsset::Register(U"net_recycle", U"image/battle/object/player/net_recycle.png");
	TextureAsset::Load(U"net_cycle");



	//player_bullet
	TextureAsset::Register(U"player_bullet_main", U"image/battle/object/player_bullet/main.png");
	TextureAsset::Load(U"player_bullet_main");

	TextureAsset::Register(U"player_bullet_sub", U"image/battle/object/player_bullet/sub.png");
	TextureAsset::Load(U"player_bullet_sub");

	//enemy
	TextureAsset::Register(U"enemy", U"image/battle/object/enemy/normal.png");
	TextureAsset::Load(U"enemy");

	TextureAsset::Register(U"enemy_normal", U"image/battle/object/enemy/normal.png");
	TextureAsset::Load(U"enemy_normal");

	TextureAsset::Register(U"enemy_garbage_can", U"image/battle/object/enemy/garbage_can.png");
	TextureAsset::Load(U"enemy_garbage_can");

	TextureAsset::Register(U"enemy_garbage_can_elite", U"image/battle/object/enemy/garbage_can_elite.png");
	TextureAsset::Load(U"enemy_garbage_can_elite");

	TextureAsset::Register(U"enemy_rumba", U"image/battle/object/enemy/rumba.png");
	TextureAsset::Load(U"enemy_rumba");

	TextureAsset::Register(U"enemy_rumba_elite", U"image/battle/object/enemy/rumba_elite.png");
	TextureAsset::Load(U"enemy_rumba_elite");

	TextureAsset::Register(U"enemy_rumba_big", U"image/battle/object/enemy/rumba_big.png");
	TextureAsset::Load(U"enemy_rumba_big");

	TextureAsset::Register(U"enemy_rumba_green", U"image/battle/object/enemy/rumba_green.png");
	TextureAsset::Load(U"enemy_rumba_green");

	TextureAsset::Register(U"enemy_rumba_baby", U"image/battle/object/enemy/rumba_baby.png");
	TextureAsset::Load(U"enemy_rumba_baby");

	TextureAsset::Register(U"enemy_boss_1", U"image/battle/object/enemy/boss_1.png");
	TextureAsset::Load(U"enemy_boss_1");

	TextureAsset::Register(U"enemy_maker", U"image/battle/object/enemy/maker.png");
	TextureAsset::Load(U"enemy_maker");


	TextureAsset::Register(U"enemy_rumba_marine", U"image/battle/object/enemy/rumba_marine.png");
	TextureAsset::Load(U"enemy_rumba_marine");

	TextureAsset::Register(U"enemy_rumba_marine_elite", U"image/battle/object/enemy/rumba_marine_elite.png");
	TextureAsset::Load(U"enemy_rumba_marine_elite");

	TextureAsset::Register(U"enemy_rumba_marine_big", U"image/battle/object/enemy/rumba_marine_big.png");
	TextureAsset::Load(U"enemy_rumba_marine_big");

	TextureAsset::Register(U"enemy_rumba_track", U"image/battle/object/enemy/rumba_track.png");
	TextureAsset::Load(U"enemy_rumba_track");

	TextureAsset::Register(U"enemy_rumba_bomb", U"image/battle/object/enemy/rumba_bomb.png");
	TextureAsset::Load(U"enemy_rumba_bomb");

	TextureAsset::Register(U"enemy_rumba_neo", U"image/battle/object/enemy/rumba_neo.png");
	TextureAsset::Load(U"enemy_rumba_neo");

	TextureAsset::Register(U"enemy_rumba_support", U"image/battle/object/enemy/rumba_support.png");
	TextureAsset::Load(U"enemy_rumba_support");

	TextureAsset::Register(U"enemy_rumba_support_2", U"image/battle/object/enemy/rumba_support_2.png");
	TextureAsset::Load(U"enemy_rumba_support_2");

	TextureAsset::Register(U"enemy_rumba_red", U"image/battle/object/enemy/rumba_red.png");
	TextureAsset::Load(U"enemy_rumba_red");

	TextureAsset::Register(U"enemy_rumba_black", U"image/battle/object/enemy/rumba_black.png");
	TextureAsset::Load(U"enemy_rumba_black");

	TextureAsset::Register(U"enemy_hard", U"image/battle/object/enemy/hard.png");
	TextureAsset::Load(U"enemy_hard");

	//enemy_bullet
	TextureAsset::Register(U"enemy_bullet_normal", U"image/battle/object/enemy_bullet/normal.png");
	TextureAsset::Load(U"enemy_bullet_normal");

	TextureAsset::Register(U"enemy_bullet_big", U"image/battle/object/enemy_bullet/big.png");
	TextureAsset::Load(U"enemy_bullet_big");

	TextureAsset::Register(U"enemy_bullet_green", U"image/battle/object/enemy_bullet/green.png");
	TextureAsset::Load(U"enemy_bullet_green");

	//Item
	TextureAsset::Register(U"burn_item", U"image/battle/object/item/burn.png");
	TextureAsset::Load(U"burn_item");

	TextureAsset::Register(U"non_burn_item", U"image/battle/object/item/non_burn.png");
	TextureAsset::Load(U"non_burn_item");

	TextureAsset::Register(U"recycle", U"image/battle/object/item/recycle.png");
	TextureAsset::Load(U"recycle_item");

	TextureAsset::Register(U"item_paper", U"image/battle/object/item/paper.png");
	TextureAsset::Load(U"item_paper");

	TextureAsset::Register(U"item_can", U"image/battle/object/item/can.png");
	TextureAsset::Load(U"item_can");

	TextureAsset::Register(U"item_news_paper", U"image/battle/object/item/news_paper.png");
	TextureAsset::Load(U"item_news_paper");

	TextureAsset::Register(U"item_battery", U"image/battle/object/item/battery.png");
	TextureAsset::Load(U"item_battery");

	TextureAsset::Register(U"item_banana", U"image/battle/object/item/banana.png");
	TextureAsset::Load(U"item_banana");

	TextureAsset::Register(U"item_branch", U"image/battle/object/item/branch.png");
	TextureAsset::Load(U"item_branch");

	TextureAsset::Register(U"item_boots", U"image/battle/object/item/boots.png");
	TextureAsset::Load(U"item_boots");

	TextureAsset::Register(U"item_umbrella", U"image/battle/object/item/umbrella.png");
	TextureAsset::Load(U"item_umbrella");

	TextureAsset::Register(U"item_glass", U"image/battle/object/item/glass.png");
	TextureAsset::Load(U"item_glass");

	TextureAsset::Register(U"item_light_bulb", U"image/battle/object/item/light_bulb.png");
	TextureAsset::Load(U"item_light_bulb");

	TextureAsset::Register(U"item_flower_pot", U"image/battle/object/item/flower_pot.png");
	TextureAsset::Load(U"item_flower_pot");

	TextureAsset::Register(U"item_bag", U"image/battle/object/item/bag.png");
	TextureAsset::Load(U"item_bag");

	TextureAsset::Register(U"item_plastic_bag", U"image/battle/object/item/plastic_bag.png");
	TextureAsset::Load(U"item_plastic_bag");

	TextureAsset::Register(U"item_bottle", U"image/battle/object/item/bottle.png");
	TextureAsset::Load(U"item_bottle");

	TextureAsset::Register(U"item_beer_bottle", U"image/battle/object/item/beer_bottle.png");
	TextureAsset::Load(U"item_beer_bottle");

	TextureAsset::Register(U"item_danbo", U"image/battle/object/item/danbo.png");
	TextureAsset::Load(U"item_danbo");

	TextureAsset::Register(U"item_milk", U"image/battle/object/item/milk.png");
	TextureAsset::Load(U"item_milk");

	//Effect

	TextureAsset::Register(U"effect_explode", U"image/battle/object/effect/explode.png");
	TextureAsset::Load(U"effect_explode");

	for (int i = 0; i < 7; i++) {

		String image_name = U"effect_explode_" + Format(i);
		String adress = U"image/battle/object/effect/explode_" + Format(i) + U".png";

		TextureAsset::Register(image_name, adress);
		TextureAsset::Load(image_name);

	}

	//Battle_UI
	TextureAsset::Register(U"frame", U"image/battle/UI/status/frame.png");
	TextureAsset::Load(U"frame");


	TextureAsset::Register(U"hp_bar", U"image/battle/UI/status/hp_bar.png");
	TextureAsset::Load(U"hp_bar");

	TextureAsset::Register(U"burn_mini", U"image/battle/UI/status/burn_mini.png");
	TextureAsset::Load(U"burn_mini");

	TextureAsset::Register(U"non_burn_mini", U"image/battle/UI/status/non_burn_mini.png");
	TextureAsset::Load(U"non_burn_mini");

	TextureAsset::Register(U"recycle_mini", U"image/battle/UI/status/recycle_mini.png");
	TextureAsset::Load(U"recycle_mini");

	TextureAsset::Register(U"gauge", U"image/battle/UI/status/gauge.png");
	TextureAsset::Load(U"gauge");

	TextureAsset::Register(U"red_gauge", U"image/battle/UI/status/red_gauge.png");
	TextureAsset::Load(U"red_gauge");

	TextureAsset::Register(U"blue_gauge", U"image/battle/UI/status/blue_gauge.png");
	TextureAsset::Load(U"blue_gauge");

	TextureAsset::Register(U"green_gauge", U"image/battle/UI/status/green_gauge.png");
	TextureAsset::Load(U"green_gauge");

	TextureAsset::Register(U"gauge_effect", U"image/battle/UI/status/gauge_effect.png");
	TextureAsset::Load(U"gauge_effect");

	//Stage_Clear
	TextureAsset::Register(U"stage_clear_doctor", U"image/battle/UI/stage_clear/doctor.png");
	TextureAsset::Load(U"stage_clear_doctor");

	//Game_Over
	TextureAsset::Register(U"game_over_doctor", U"image/battle/UI/game_over/doctor.png");
	TextureAsset::Load(U"game_over_doctor");



	//Stage_Select
	TextureAsset::Register(U"stage_select_back", U"image/stage_select/back.png");
	TextureAsset::Load(U"stage_select_back");

	TextureAsset::Register(U"stage_select_box", U"image/stage_select/box.png");
	TextureAsset::Load(U"stage_select_box");

	for (int i = 0; i < 3; i++) {

		String name = U"stage_select_box_" + Format(i + 1);
		String adress = U"image/stage_select/box_" + Format(i + 1) + U".png";

		TextureAsset::Register(name, adress);
		TextureAsset::Load(name);
	}



	TextureAsset::Register(U"stage_select_cur", U"image/stage_select/cur.png");
	TextureAsset::Load(U"stage_select_cur");

	TextureAsset::Register(U"stage_select_doctor", U"image/stage_select/doctor.png");
	TextureAsset::Load(U"stage_select_doctor");

	TextureAsset::Register(U"stage_select_tips", U"image/stage_select/tips.png");
	TextureAsset::Load(U"stage_select_tips");


}

void Game::load_music() {

	//bgm
	for (int i = 0; i < 20; i++) {
		String str;
		str = U"bgm{}"_fmt(i);
		bgm << str;
	}

	//se
	for (int i = 0; i < 50; i++) {
		String str;
		str = U"se{}"_fmt(i);
		se << str;
	}

	

	//BGM
	AudioAsset::Register(bgm[0], Audio::Stream, U"music/bgm/Digital_Space.mp3", Loop::Yes);
	//AudioAsset::Load(bgm[0]);
	AudioAsset::Register(bgm[1], Audio::Stream, U"music/bgm/Tokyo_Dungeon.mp3", Loop::Yes);
	//AudioAsset::Load(bgm[1]);

	//SE
	AudioAsset::Register(se[0], U"music/se/プレイヤーショット.mp3");
	AudioAsset::Load(se[0]);


}

void Game::load_font() {

	FontAsset::Register(U"UDP_G_R_25", 25, U"font/BIZUDPGothic-Regular.ttf");
	FontAsset::Register(U"UDP_G_B_40", 40, U"font/BIZUDPGothic-Bold.ttf");

	FontAsset::Register(U"UD_G_B_60", 60, U"font/BIZUDGothic-Bold.ttf");
	FontAsset::Register(U"UD_G_R_60", 60, U"font/BIZUDGothic-Regular.ttf");

	FontAsset::Register(U"UDP_G_B_100", 100, U"font/BIZUDPGothic-Bold.ttf");
	FontAsset::Register(U"UDP_G_R_60", 60, U"font/BIZUDPGothic-Regular.ttf");

	FontAsset::Register(U"UDP_G_B_70", 70, U"font/BIZUDPGothic-Bold.ttf");

	FontAsset::Register(U"KIKA_R_20", 20, U"font/Kikakana-21-Bold.otf");
	FontAsset::Register(U"KIKA_R_30", 30, U"font/Kikakana-21-Bold.otf");

	FontAsset::Register(U"KIKA_R_120", 120, U"font/Kikakana-21-Bold.otf");

	FontAsset::Register(U"UD_M_B_50", 50, U"font/BIZUDPGothic-Bold.ttf");

	FontAsset::Register(U"UD_M_B_40", 40, U"font/BIZUDPGothic-Bold.ttf");
}

void Game::debug_data() {

	main_scene = U"title";

	//main_scene = U"stage_select";
	//main_scene = U"stageclear";

	stage = 1;
	
}

void Game::set_up_develop() {

	{

		const int edge_x = 1200;
		const int edge_y = 200;
		const int size_w = 600;
		const int size_h = 100;

		const int space_h = 150;

		String name;

		for (int i = 0; i < 3; i++) {

			int x = edge_x;
			int y = edge_y + space_h * i;

			if (i == 0) {
				name = U"Rect";
			}
			else if (i == 1) {
				name = U"Circle";
			}
			else if (i == 2) {
				name = U"Quad";
			}

			develop_select_rect.push_back(Develop_Select_Rect(x, y, size_w, size_h, name));

		}

	}


	{

		const int edge_x = 50;
		const int edge_y = 200;
		const int size_w = 100;
		const int size_h = 100;

		const int space_h = 150;

		String name;

		for (int i = 0; i < 3; i++) {

			int x = edge_x;
			int y = edge_y + space_h * i;

			if (i == 0) {
				name = U"item";
			}
			else if (i == 1) {
				name = U"enemy";
			}
			else if (i == 2) {
				name = U"bullet";
			}

			develop_kind_select_rect.push_back(Develop_Kind_Select_Rect(x, y, size_w, size_h, name));

		}

	}
}

void Game::set_shader() {

	psWhite = HLSL{ U"shader/white.hlsl", U"PS" };
	if (not psWhite)
	{
		throw Error{ U"Failed to load a shader file" };
	}
}
