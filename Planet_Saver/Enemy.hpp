#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12



class Enemy {

public:

	Enemy(String, double, double);

	Enemy(String, String, int, int, int, int, String);

	void update(double);
	void draw();

	void each();

	void damage(int);
	int get_hp() { return hp; }
	double get_count() { return count; }
	bool get_boss() { return boss; }
	String get_item() { return item; }

	int get_make_bullet() { return make_bullet; }
	void set_make_bullet_done() { make_bullet = -1; }

	void move();

	void straight_move();
	void curve_move();


	int get_score() { return score; }

	String get_shape() { return shape; }
	RectF get_rect() { return rect; }
	Circle get_circle() { return circle; }
	Quad get_quad();

	double get_center_x() { return rect.x + rect.w / 2; }
	double get_center_y() { return rect.y + rect.h / 2; }

	//shader
	bool get_white() {
		if (white_count > 0) {
			return true;
		}
		return false;
	}

	double get_white_count() { return white_count; }

private:

	double d_time;

	String name = U"";

	String shape = U"";

	RectF rect;

	Quad quad;

	Circle circle;

	double speed;

	String pattern = U"";

	int hp;

	int score = 0;

	String item = U"";

	double count = 0;

	int make_bullet = -1;

	bool boss = false;

	//shader

	bool white = false;

	double white_count = 0;

	//Move_V

	double start_x = 0;
	double start_y = 0;

	double move_count = 0;



	double move_v_0 = 0;

	double move_angle = 0;

	double move_v_1 = 0;

};

