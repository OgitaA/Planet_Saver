#include"Back_Object.hpp"


Back_Object::Back_Object(String _name, int _y) {

	name = _name;

	rect = Rect(1950, _y, 100, 100);
}

Back_Object::Back_Object(String _name, int _y, String _layer) {

	name = _name;

	rect = Rect(1950, _y, 100, 100);

	layer = Parse<int>(_layer);
}


//layerはスルー
Back_Object::Back_Object(String _name, int _y, String _layer,String _direction) {

	name = _name;

	rect = Rect(1950, _y, 100, 100);

	//layer = Parse<int>(_layer);

	direction = _direction;
}

Back_Object::Back_Object(String _name,String _direction,int _x,int _y,int _layer) {

	name = _name;

	direction = _direction;

	rect = Rect(_x, _y, 100, 100);

	layer = _layer;

}


void Back_Object::update(double _scroll_speed) {

	if (direction == U"left") {

		rect.x -= _scroll_speed;

	}
	else if (direction == U"up") {

		rect.y -= _scroll_speed;
	}
}

void Back_Object::update(double _scroll_speed,double _up_scroll_speed) {

	if (direction == U"left") {

		rect.x -= _scroll_speed;

	}
	else if (direction == U"up") {

		rect.x -= _scroll_speed;
		rect.y -= _up_scroll_speed;
	}
}




void Back_Object::draw() {

	String image_name = U"back_object_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);

}
