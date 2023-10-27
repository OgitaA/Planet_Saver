#include"Game.hpp"

void Game::update_stage(double _d_time) {

	//更新
	for (auto& d : back_object_data) {

		d.update(_d_time);

	}


	//生成
	for (auto& d : back_object_data) {

		if (d.get_emerge()) {

			String name = d.get_name();
			int y = d.get_y();
			String layer = d.get_layer();

			if (layer == U"0") {
				make_back_object(name, y);
			}
			else if (layer == U"1") {
				make_back_object(name, y, U"1");
			}
		}
	}



	//削除
	back_object.remove_if([&](Back_Object b)
			{

				if (b.get_rect().x < -500) {

					return true;
				}
				else {
					return false;
				}
			});



}



void Game::make_back_object(String _name, int _y) {

	back_object.push_back(Back_Object(_name, _y));
}

//レイヤーつき
void Game::make_back_object(String _name, int _y, String _layer) {

	back_object.push_back(Back_Object(_name, _y, _layer));
}
