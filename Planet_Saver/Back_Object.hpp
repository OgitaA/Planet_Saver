#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Back_Object {

public:

	Back_Object(String, int);
	Back_Object(String, int, String);
	Back_Object(String, int, String,String);

	Back_Object(String, String, int,int,int);

	void update(double);
	void update(double, double);
	void draw();

	RectF get_rect() { return rect; }
	int get_layer() { return layer; }
	String get_direction() { return direction; }

private:

	String name = U"";

	RectF rect;

	int layer = 0;

	String direction = U"left";



};
