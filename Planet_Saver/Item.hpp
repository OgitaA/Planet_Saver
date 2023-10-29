#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.12

class Item {

public:

	Item(String, double, double);

	void update(double);
	void draw();

	void set_data();

	
	String get_name() { return name; }
	String get_type() { return type; }

	String get_shape() { return shape; }
	RectF get_rect() { return rect; }
	Circle get_circle() { return circle; }
	Quad get_quad();

	void move();

	void draw_shape();

private:

	double d_time;

	String name = U"";

	String type = U"";

	double speed;

	String shape = U"";

	RectF rect;

	Circle circle;

	Quad quad;


	
};
