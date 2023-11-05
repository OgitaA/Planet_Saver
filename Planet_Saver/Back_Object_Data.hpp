#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.12

class Back_Object_Data {

public:

	//ニュー
	Back_Object_Data(String _name, String _direction,int _x,int _y,int _layer,double _count) {

		name = _name;
		direction = _direction;
		x = _x;
		y = _y;
		layer = _layer;
		emerge_count = _count;
	}

	//ニューランダム
	Back_Object_Data(String _name, String _direction, int _x, int _y, int _layer,double _count,int _random_v) {

		name = _name;
		direction = _direction;
		x = _x;
		y = _y;
		layer = _layer;
		emerge_count = _count;
		random_v = _random_v;
	}

	void update(double _d_time) {
		count += _d_time;
	}

	String get_name() { return name; }

    String get_direction() { return direction; }

	bool get_emerge() {

		if (count >= emerge_count) {
			//Print << U"count::" << count;
			//Print << U"emerge_count::" << emerge_count;
			count = 0;
			return true;
		}
		else {
			return false;
		}
	}

	int get_x() { return x; }

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

	int get_layer() { return layer; }

	double get_emerge_count() { return emerge_count; }

private:

	double count = 0;
	double emerge_count = 10;

	String name = U"";
	String direction = U"";
	

	int x = 0;
	int y = 600;

	
	int layer = 0;
	int random_v = 0;
	
};
