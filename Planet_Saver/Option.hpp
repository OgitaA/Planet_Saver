#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Option {

public:

	Option(double _x,double _y) {
		rect = Rect(_x, _y, 56, 56);
	}

	void update();

	void draw() { TextureAsset(U"player_option").draw(rect.x, rect.y); }

	void set_pos_x(double v) { rect.x = v; }
	void set_pos_y(double v) { rect.y = v; }

	double get_x() { return rect.x; }
	double get_y() { return rect.y; }

	int get_size() { return rect.w; }

private:

	Rect rect;


};
