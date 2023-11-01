#include"Catcher.hpp"

void Catcher::reset() {

	operation = false;

	count = 0;

	status = U"down";

	move_y = 0;

	item.clear();
}

void Catcher::first(double _p_x, double _p_y) {

	rect.x = _p_x + adjust_x;
	rect.y = _p_y + adjust_y;

	hit_rect = rect;
}

void Catcher::update(double _d_time, double _p_x, double _p_y, String _mode) {

	mode = _mode;

	if (operation == false) {

		if(miss==false){

			if (KeyZ.down()) {

				if (error == false) {

					operation = true;
				}
			}
		}
	}

	if (operation == true) {

		count += _d_time;

		if (status == U"down") {

			move_y += _d_time * speed;

			if (count >= 0.5) {

				//operation = false;

				move_y = speed * 0.5;

				count = 0;

				status = U"up";
			}
		}
		else if (status == U"up") {

			move_y -= _d_time * speed;

			if (count >= 0.5) {

				operation = false;

				move_y = 0;

				count = 0;

				status = U"down";
			}

		}


	}



	rect.x = _p_x + adjust_x;
	rect.y = _p_y + adjust_y + move_y;

	

	hit_rect = rect;
}

void Catcher::draw() {

	//キャッチしたゴミ

	class Item_Data {
	  public:
		  String name = U"";
		  int x = 0;
	};



	Array<Item_Data> item_data;

	for (size_t i = 0; i < item.size();i++) {

		item_data.push_back(Item_Data());


		String item_name = U"item_" + item[i].name;

		item_data[i].name = item_name;



		int x = hit_rect.x + rect.w / 2 - (100 * 0.5 / 2);

		//center
		if (i == 0) {
			
		}
		else if (i == 1) {
			x -= 50/2;
		}
		else if (i == 2) {
			x += 50 / 2;
		}

		item_data[i].x = x;
	}

	int item_y = hit_rect.y - (100 * 0.5 / 2);

	for (size_t i = item_data.size(); i >0; i--) {

		int index = i - 1;

		String item_name = item_data[index].name;
		int item_x = item_data[index].x;

		TextureAsset(item_name).scaled(0.5).draw(item_x,item_y);
	}

	String image_name = U"net_" + mode;

	TextureAsset(image_name).draw(rect.x, rect.y);

	//hit_rect.drawFrame(5, Palette::Blue);

}

