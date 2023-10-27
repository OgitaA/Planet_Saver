#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Back_Object {

public:

	Back_Object(String, int);
	Back_Object(String, int, String);

	void update(double);
	void draw();

	RectF get_rect() { return rect; }
	int get_layer() { return layer; }

private:

	String name = U"";

	RectF rect;

	int layer = 0;



};
