#include"Game.hpp"

void Game::make_stage(int _stage) {

	score = 0;

	player.reset();
	player_bullet.clear();
	emerge_enemy.clear();
	enemy.clear();
	enemy_bullet.clear();
	item.clear();

	back_object.clear();
	back_object_data.clear();

	//エネミーデータをロード
	load_enemy_data(_stage);

	//背景画像を設定
	back.set_stage(_stage);



	//背景オブジェクトを設定
	switch (_stage)
	{
	case 1:
		set_stage_1();
		break;
	case 2:
		set_stage_2();
		break;
	case 3:
		set_stage_3();
		break;
	default:
		break;
	}
}

void Game::load_enemy_data(int _stage) {


	String adress = U"data/" + Format(_stage) + U"/stage.csv";

	const CSV csv{ adress };
	if (!csv) {
		throw Error(U"Error::" + adress);
	}


	//縦
	for (size_t row = 0; row < csv.rows() - 1; row++) {

		String enemy_or_item;

		double stage_time = 0;
		String name;

		String pattern;

		int pos_x;
		int pos_y;
		int hp;
		int score;
		String item;

		int cell_y = row + 1;


		enemy_or_item = Parse<String>(csv[cell_y][0]);

		//Enemy
		if (enemy_or_item == U"E") {

			//横
			for (int x = 0; x < 9; x++) {

				switch (x)
				{
				case 1:
					stage_time = Parse<double>(csv[cell_y][x]);
					break;
				case 2:
					name = Parse<String>(csv[cell_y][x]);
					break;
				case 3:
					pattern = Parse<String>(csv[cell_y][x]);
					break;
				case 4:
					pos_x = Parse<int>(csv[cell_y][x]);
					break;
				case 5:
					pos_y = Parse<int>(csv[cell_y][x]);
					break;
				case 6:
					hp = Parse<int>(csv[cell_y][x]);
					break;
				case 7:
					score = Parse<int>(csv[cell_y][x]);
					break;
				case 8:
					item = Parse<String>(csv[cell_y][x]);
					break;

				}

			}

			emerge_enemy.push_back(Emerge_Enemy(stage_time, name, pattern, pos_x, pos_y, hp, score, item));


		}

		//Item
		else if (enemy_or_item == U"I") {

			for (int x = 0; x < 6; x++) {

				switch (x)
				{
				case 1:
					stage_time = Parse<double>(csv[cell_y][x]);
					break;
				case 2:
					name = Parse<String>(csv[cell_y][x]);
					break;
				case 4:
					pos_x = Parse<int>(csv[cell_y][x]);
					break;
				case 5:
					pos_y = Parse<int>(csv[cell_y][x]);
					break;
				default:
					break;
				}
			}

			emerge_item.push_back(Emerge_Item(stage_time, name, pos_x, pos_y));

		}



	}

}


void Game::set_stage_1() {

	stage_scroll_speed = 800;
	stage_scroll_speed_2 = 600;

	make_back_object_data(U"bill_3", 1080 - 45 - 280, 0.14, U"1");

	make_back_object_data(U"bill_2", 1080 - 45 - 280, 0.2, U"1");

	make_back_object_data(U"bill_3", 1080 - 45 - 280, 0.25, U"1");

	make_back_object_data(U"bill_3", 1080 - 45 - 280, 2, U"1");

	make_back_object_data(U"bill_2", 1080 - 45 - 280, 1.3, U"1");

	make_back_object_data(U"bill_4", 1080 - 45 - 280, 0.753);

	make_back_object_data(U"bill_5", 1080 - 45 - 280, 0.23);

	make_back_object_data(U"bill_6", 1080 - 45 - 280, 1.7);

	make_back_object_data(U"bill", 1080 - 45 - 280, 1);

	make_back_object_data(U"tree_big", 1080 - 45 - 120, 0.8);

	make_back_object_data(U"tree_big", 1080 - 45 - 120, 0.78);

	make_back_object_data(U"tree_big", 1080 - 45 - 120, 2.8);

	make_back_object_data(U"tree_big", 1080 - 45 - 120, 3.5);

	make_back_object_data(U"tree_small", 1080 - 45 - 75, 0.55);

	make_back_object_data(U"tree_small", 1080 - 45 - 75, 7.5);

	make_back_object_data(U"tree_small", 1080 - 45 - 75, 0.4);

	make_back_object_data(U"tree_small", 1080 - 45 - 75, 0.9);

	make_back_object_data(U"crowd", 300, 1.3, 200);

	make_back_object_data(U"crowd", 300, 0.5, 200);

}

void Game::set_stage_2() {

}

void Game::set_stage_3() {

}

void Game::make_back_object_data(String _name, int _y, double _count) {

	back_object_data.push_back(Back_Object_Data(_name, _y, _count));
}

void Game::make_back_object_data(String _name, int _y, double _count, String _layer) {

	back_object_data.push_back(Back_Object_Data(_name, _y, _count, _layer));
}


void Game::make_back_object_data(String _name, int _y, double _count, int _random_v) {

	back_object_data.push_back(Back_Object_Data(_name, _y, _count, _random_v));
}
