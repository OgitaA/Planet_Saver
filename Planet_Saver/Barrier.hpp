#pragma once

class Barrier {

public:

	Barrier();

	void update(double,double, double);

	void draw();

	Array<Triangle> get_triangle(){ return triangle; }

	void make_triangle_up(int,int,int,int);

    void make_triangle_down(int, int, int, int);

	void damage() { damaged = true; }

	bool get_delete() {

		if (damage_count > delete_count) {
			return true;
		}

		return false;
	}

	void set_renew() {
		damaged = false;
		damage_count = 0;
	}

	Triangle get_triangle(int _index) { return moved_triangle[_index]; }

private:

	Array<Triangle> triangle;

	Array<Triangle> moved_triangle;

	bool damaged = false;

	double damage_count = 0;

	double delete_count = 3;

	

};
