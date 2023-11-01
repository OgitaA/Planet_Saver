#include"Game.hpp"

void Game::update_stage(double _d_time) {

	//更新
	for (auto& d : back_object_data) {

		d.update(_d_time);

	}


	//生成
	for (auto& d : back_object_data) {

		if (d.get_emerge()==true) {

			String name = d.get_name();
			int x = d.get_x();
			int y = d.get_y();
			int layer = d.get_layer();
			String direction = d.get_direction();


			make_back_object(name, direction, x, y, layer);

		}
	}



	//削除
	back_object.remove_if([&](Back_Object b)
			{

				if (b.get_rect().x < -500 or b.get_rect().y<-500) {

					return true;
				}
				else {
					return false;
				}
			});



}



//ニュー
void Game::make_back_object(String _name,String _direction,int _x,int _y,int _layer) {

	back_object.push_back(Back_Object(_name, _direction, _x, _y, _layer));
}
