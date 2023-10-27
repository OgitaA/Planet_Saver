#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.12

class Back_Object_Data {

public:

	Back_Object_Data(String _name, int _y, double _emerge_count) {
		name = _name;
		y = _y;
		emerge_count = _emerge_count;
	}

	Back_Object_Data(String _name, int _y, double _emerge_count, String _layer) {
		name = _name;
		y = _y;
		emerge_count = _emerge_count;
		layer = _layer;
	}

	Back_Object_Data(String _name, int _y, double _emerge_count, int _random_v) {
		name = _name;
		y = _y;
		emerge_count = _emerge_count;
		random_v = _random_v;
	}



	void update(double _d_time) {
		count += _d_time;
	}

	String get_name() { return name; }

	bool get_emerge() {

		if (count >= emerge_count) {

			count = 0;
			return true;
		}
		else {
			return false;
		}
	}

	int get_y() {

		if (random_v == 0) {
			return y;
		}
		else {
			int up_down = Random(1);
			int v = Random(random_v);

			if (up_down == 0) {
				return y - v;
			}
			else if (up_down == 1) {
				return y + v;
			}
		}

	}

	String get_layer() { return layer; }

private:

	String name = U"";

	double count = 0;

	double emerge_count = 10;

	int y = 600;

	int random_v = 0;

	String layer = U"0";
};
