#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.12

class Item {

public:

	Item(String, double, double);

	void update(double);
	void draw();

	void set_type();

	RectF get_rect() { return rect; }
	String get_name() { return name; }

	void move();

private:

	double d_time;

	String name = U"";

	String type = U"";

	RectF rect;

	double speed;

	
};
