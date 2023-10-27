#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Emerge_Item {

public:

	Emerge_Item(double _stage_time, String _name, int _x, int _y) {

		stage_time = _stage_time;
		name = _name;
		x = _x;
		y = _y;
	}

	double get_stage_time() { return stage_time; }
	String get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }


	bool get_done() { return done; }
	void set_done() { done = true; }

private:

	double stage_time;

	String name = U"";

	int x, y;

	bool done = false;
};
