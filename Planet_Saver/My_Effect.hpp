#pragma once

class My_Effect {

public:

	My_Effect(String _name,double _x,double _y) {
		name = _name;
		x = _x;
		y = _y;
	}

	void update(double);
	void draw();

	void set_up();

private:

	String name;

	double x;
	double y;

	double count = 0;

	double delete_count;

};
