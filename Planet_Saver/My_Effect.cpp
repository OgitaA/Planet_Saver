#include"My_Effect.hpp"

void My_Effect::set_up() {

	if (name == U"test") {

		w = 100;
		h = 100;

        //初期サイズ
		size = 0;

		size_up = 1.5 * 2;

		delete_count = 0.5;

	}
	else if (name == U"explode") {

		w = 500;
		h = 500;

		//初期サイズ
		size = 0.28;

		size_up = 0;

		delete_count = 0.3;



		anime_use = true;

		page_max = 7;
	}
	else if (name == U"mini_explode") {

		w = 500;
		h = 500;

		//初期サイズ
		size = 0.14;

		size_up = 0;

		delete_count = 0.3;



		anime_use = true;

		page_max = 7;

		name = U"explode";
	}
	else if (name == U"middle_explode") {

		w = 500;
		h = 500;

		//初期サイズ
		size = 0.3;

		size_up = 0;

		delete_count = 0.3;



		anime_use = true;

		page_max = 7;

		name = U"explode";
	}
	else if (name == U"explode_custom_1.5") {

		w = 500;
		h = 500;

		//初期サイズ
		size = 0.42;

		size_up = 0;

		delete_count = 0.3;



		anime_use = true;

		page_max = 7;

		name = U"explode";
	}
	else if (name == U"explode_custom_2") {

		w = 500;
		h = 500;

		//初期サイズ
		size = 0.28;

		size_up = 0;

		delete_count = 0.3;



		anime_use = true;

		page_max = 7;

		name = U"explode";
	}
	else if (name == U"player_explode") {


	}



	adjust_x = w * size / 2;
	adjust_y = h * size / 2;
	fade_minus = 1 / delete_count;

	page_change_count = delete_count / (page_max - 1);
}

void My_Effect::update(double _d_time) {

	count += _d_time;

	if (anime_use == false) {

		size += size_up * _d_time;
		size -= size_down * _d_time;

		if (size < 0) {
			size = 0;
		}

		adjust_x = (w * size / 2);
		adjust_y = (h * size / 2);

		fade_v -= fade_minus * _d_time;
		fade_v += fade_plus * _d_time;


	}
	else if (anime_use == true) {

		page_count += _d_time;

		if (page_count > page_change_count) {

			page++;
			page_count = 0;
		}
	}

}

void My_Effect::draw() {

	if (anime_use == false) {

		String image_name = U"effect_" + name;

		TextureAsset(image_name).scaled(size).draw(x - adjust_x, y - adjust_y, ColorF(1.0, fade_v));

	}
	else if (anime_use == true) {

		String image_name = U"effect_" + name + U"_" + Format(page);

		TextureAsset(image_name).scaled(size).draw(x - adjust_x, y - adjust_y, ColorF(1.0, 1));

		

	}
}
