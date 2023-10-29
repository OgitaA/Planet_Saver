#pragma once

class Barrier {

public:

	Barrier();

	void update(double, double);

	void draw();

	Array<Triangle> get_triangle(){ return triangle; }

	void make_triangle_up(int,int,int,int);

    void make_triangle_down(int, int, int, int);


private:

	Array<Triangle> triangle;

	Array<Triangle> moved_triangle;

};
