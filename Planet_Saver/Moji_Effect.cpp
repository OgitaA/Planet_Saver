#include"Moji_Effect.hpp"

Moji_Effect::Moji_Effect(String _text,int _x,int _y,String _color_type) {

	text = _text;
	x = _x;
	y = _y;
	color_type = _color_type;

}

void Moji_Effect::update(double _d_time) {

	count += _d_time;
}

void Moji_Effect::draw() {

	Color color = Palette::Gray;

	if (color_type == U"Red") {
		color = Palette::Red;
	}
	else if (color_type == U"Blue") {
		color = Palette::Blue;
	}
	else if (color_type == U"Green") {
		color = Palette::Green;
	}

	/*
	Print << U"text::" << text;
	Print << U"x::" << x;
	Print << U"y::" << y;
	Print << U"color::" << color;
*/

	FontAsset(U"KIKA_R_20")(text).drawAt(x, y, Color(color));
}
