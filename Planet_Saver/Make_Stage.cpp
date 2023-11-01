#include"Game.hpp"

void Game::make_stage(int _stage) {

	stage_time = 0;
	score = 0;
	remain = 3;

	player.reset();
	player_bullet.clear();
	emerge_enemy.clear();
    enemy.clear();
    enemy_bullet.clear();
	emerge_item.clear();
	item.clear();

    back_object_data.clear();
	back_object.clear();
	

	my_effect.clear();
	moji_effect.clear();
	gauge_effect.clear();

	se_will.clear();
	se_lock.clear();

	


	//ステージデータをロード
	load_stage_data(_stage);

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

void Game::load_stage_data(int _stage) {


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

	//スクロールスペード設定
	stage_scroll_speed_layer_0 = 800;
	stage_scroll_speed_layer_1 = 600;

	//流れる方向
	String direction = U"left";

	//地面
	int bottom = 45;

	//生成位置
	int x = 1920;

	//ビル
	{
		String name = U"tree_big";
		int y = 1080 - 280 - bottom;
		int layer = 0;

		//手前

		make_back_object_data(U"bill_4", direction, x, y, layer, 0.753);

		make_back_object_data(U"bill_5", direction, x, y, layer, 0.23);

		make_back_object_data(U"bill_6", direction, x, y, layer, 1.7);

		make_back_object_data(U"bill", direction, x, y, layer, 1);


		layer = 1;

		make_back_object_data(U"bill_3", direction, x, y, layer, 0.14);

		make_back_object_data(U"bill_2", direction, x, y, layer, 0.2);

		make_back_object_data(U"bill_3", direction, x, y, layer, 0.25);

		make_back_object_data(U"bill_3", direction, x, y, layer, 2);

		make_back_object_data(U"bill_2", direction, x, y, layer, 1.3);


	}

	//木・大
	{

		String name = U"tree_big";
		int y = 1080 - 120 - bottom;
		int layer = 0;

		make_back_object_data(name, direction, x, y, layer, 0.8);

		make_back_object_data(name, direction, x, y, layer, 0.78);

		make_back_object_data(name, direction, x, y, layer, 2.8);

		make_back_object_data(name, direction, x, y, layer, 3.5);

	}

	//木・小

	{
		String name = U"tree_small";
		int y = 1080 - 75 - bottom;
		int layer = 0;

		make_back_object_data(name, direction, x, y, layer, 0.55);

		make_back_object_data(name, direction, x, y, layer, 7.5);

		make_back_object_data(name, direction, x, y, layer, 0.4);

		make_back_object_data(name, direction, x, y, layer, 0.9);

	}

	//雲

	{
		String name = U"crowd";
		int y = 300;
		int layer = 0;
		double random_v = 200;

		make_back_object_data(name, direction, x, y, layer, 1.3, random_v);

		make_back_object_data(name, direction, x, y, layer, 0.5, random_v);

		
	}
}

void Game::set_stage_2() {

	//スクロールスペード設定
	stage_scroll_speed_layer_0 = 2;
	stage_up_scroll_speed = 30;

	int bubble_x;
	String direction = U"up";
	int x = 1920 / 2;
	int y = 1080 + 100;
	int layer = 0;

	//泡

	//make_back_object_data(U"bubble", direction, x, y, layer, 0.5);

	//サカナ

}

void Game::set_stage_3() {

}



//ニュー
void Game::make_back_object_data(String _name,String _direction,int _x,int _y,int _layer,double _count) {

	back_object_data.push_back(Back_Object_Data(_name, _direction, _x, _y, _layer, _count));
}

//ニューランダム
void Game::make_back_object_data(String _name, String _direction, int _x, int _y,int _layer,double _count,int _random) {

	back_object_data.push_back(Back_Object_Data(_name, _direction, _x, _y, _layer,_count,_random));
}
