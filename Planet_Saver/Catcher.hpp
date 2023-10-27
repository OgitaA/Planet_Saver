#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Catcher {

public:

	Catcher() {

		rect = Rect(0, 0, 118, 41);

		hit_rect = rect;
	}

	void first(double, double);

	void update(double, double, double, String);

	void draw();

	void reset();

	RectF get_hit_rect() { return hit_rect; }

	void get_() {}

private:

	RectF rect;

	double adjust_x = 0;
	const double adjust_y = 28;

	double move_y = 0;

	bool operation = false;

	String status = U"down";

	double speed = 400;

	double count = 0;

	RectF hit_rect;

	String mode = U"burn";
};
