#include"Barrier.hpp"



Barrier::Barrier() {

	int w = 150;
	int h = 90;

	int unit_w = w / 6;
	int unit_h = h / 2;
	
	int a_x = 0;
	int a_y = 0;

	//上段・上向き
	make_triangle_up(a_x,a_y,unit_w,unit_h);
	make_triangle_up(a_x + unit_w * 2, a_y, unit_w, unit_h);
	make_triangle_up(a_x + unit_w * 4, a_y, unit_w, unit_h);

	//下段・上向き
	make_triangle_up(a_x + unit_w * 1, a_y + unit_h, unit_w, unit_h);
	make_triangle_up(a_x + unit_w * 3, a_y + unit_h, unit_w, unit_h);

	//上段・下向き
	make_triangle_down(a_x + unit_w, a_y + unit_h, unit_w, unit_h);
	make_triangle_down(a_x + unit_w * 3, a_y + unit_h, unit_w, unit_h);

	//下段・下向き
	make_triangle_down(a_x, a_y + unit_h * 2, unit_w, unit_h);
	make_triangle_down(a_x + unit_w * 2, a_y + unit_h * 2, unit_w, unit_h);
	make_triangle_down(a_x + unit_w * 4, a_y + unit_h * 2, unit_w, unit_h);

	for (size_t t = 0; t < triangle.size(); t++) {
		moved_triangle.push_back(Triangle());
	}

}

void Barrier::make_triangle_up(int _x,int _y,int _w,int _h) {

	Vec2 a_1{ _x,_y };

	Vec2 a_2{ _x - _w,_y + _h };

	Vec2 a_3{ _x + _w,_y + _h };

	triangle.push_back(Triangle(a_1, a_2, a_3));

}

void Barrier::make_triangle_down(int _x, int _y, int _w, int _h) {

	Vec2 a_1{ _x,_y };

	Vec2 a_2{ _x - _w,_y - _h };

	Vec2 a_3{ _x + _w,_y - _h };

	triangle.push_back(Triangle(a_1, a_2, a_3));

}

void Barrier::update(double _d_time,double _p_x, double _p_y) {

	for (size_t t = 0; t < triangle.size();t++) {
		moved_triangle[t] = triangle[t].movedBy(_p_x - 50, _p_y - 45);
	}

	if (damaged==true) {
		damage_count += _d_time;
	}
}

void Barrier::draw() {

	for (auto& t : moved_triangle) {
		t.draw(Palette::Green);
	}
}
