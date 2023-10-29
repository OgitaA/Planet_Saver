﻿#include"Item.hpp"

Item::Item(String _name, double _x, double _y) {

	name = _name;

	set_data();

	rect = Rect(_x, _y, 100, 100);

	speed = 300;

	
}

void Item::set_data() {

	if (U"paper" == name) {

		type = U"burn";
		shape = U"Rect";
	}
	else if (U"can" == name) {
		type = U"recycle";
		shape = U"Quad";
		quad = Quad({38,4},{10,76},{58,94},{85,22});
	}
}

void Item::update(double _d_time) {

	d_time = _d_time;

	move();
}


void Item::draw() {

	String image_name = U"item_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);
}


void Item::move() {
	rect.x -= speed * d_time;
}

void Item::draw_shape() {

	if (shape == U"Rect") {
		rect.drawFrame(10, Palette::Red);
	}
	else if (shape == U"Circle") {
		circle.drawFrame(10, Palette::Red);
	}
	else if (shape == U"Quad") {
		quad.drawFrame(10, Palette::Red);
	}


}


Quad Item::get_quad() {

	Quad quad_v({ rect.x + quad.p0.x, rect.y + quad.p0.y },{ rect.x + quad.p1.x, rect.y + quad.p1.y },{ rect.x + quad.p2.x, rect.y + quad.p2.y },{ rect.x + quad.p3.x, rect.y + quad.p3.y });

	return quad_v;

}
