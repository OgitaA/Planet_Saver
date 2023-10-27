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

	bool get_operation() {return  operation; }

	void plus_item(String v) { item.push_back(v); }

	bool check_full_item(){

		if (item.size() >= item_max) {
			return true;
		}
		else {
			return false;
		}
	}

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

	//キャッチしたアイテム

	Array<String> item;

	int item_max = 3;
};
