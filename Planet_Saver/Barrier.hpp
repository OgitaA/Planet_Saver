#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Barrier {

public:

	Barrier();

	void update(double,double, double);

	void draw();

	Array<Triangle> get_moved_triangle(){ return moved_triangle; }
    Triangle get_moved_triangle_one(int _index) { return moved_triangle[_index]; }


	void make_triangle_up(int,int,int,int);

    void make_triangle_down(int, int, int, int);

	void damage() { damaged = true; }

	bool get_delete() {

		if (damage_count > delete_count) {

			
			reset();

			return true;
		}

		return false;
	}

	void reset() {

		damaged = false;
		damage_count = 0;

		flash_count = 0;
		damage_flash = false;
	}

	

private:

	Array<Triangle> triangle;

	Array<Triangle> moved_triangle;

	bool damaged = false;

	double damage_count = 0;

	double delete_count = 2;

	double flash_count = 0;
	bool damage_flash = false;

};
