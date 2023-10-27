#include"Catcher.hpp"

void Catcher::reset() {

	operation = false;

	count = 0;

	status = U"down";

	move_y = 0;

	
}

void Catcher::first(double _p_x, double _p_y) {

	rect.x = _p_x + adjust_x;
	rect.y = _p_y + adjust_y;

	hit_rect = rect;
}

void Catcher::update(double _d_time, double _p_x, double _p_y, String _mode) {

	mode = _mode;

	if (operation == false) {

		if (KeyZ.down()) {
			operation = true;
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

	String image_name = U"net_" + mode;

	TextureAsset(image_name).draw(rect.x, rect.y);

	//hit_rect.drawFrame(5,Palette::Blue);
}
