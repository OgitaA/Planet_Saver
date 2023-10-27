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


void Back_Object::update(double _scroll_speed) {

	rect.x -= _scroll_speed;
}

void Back_Object::draw() {

	String image_name = U"back_object_" + name;

	TextureAsset(image_name).draw(rect.x, rect.y);

}
