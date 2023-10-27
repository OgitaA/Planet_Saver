#pragma once
class Stage_Select_Box {

public:

	Stage_Select_Box(int _number, String _name) {

		number = _number;
		name = _name;
	}

	int get_number() { return number; }
	String get_name() { return name; }

	int get_x() { return x; }
	int get_y() { return y; }


private:

	int number = 0;

	String name = U"";

	int x, y;

};
