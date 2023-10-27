#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Emerge_Enemy {

public:

	Emerge_Enemy(double _stage_time, String _name, String _pattern, int _x, int _y, int _hp, int _score, String _item) {

		stage_time = _stage_time;

		name = _name;

		pattern = _pattern;

		x = _x;

		y = _y;

		hp = _hp;

		score = _score;

		item = _item;

	}

	double get_stage_time() { return stage_time; }
	String get_name() { return name; }
	String get_pattern() { return pattern; }
	int get_x() { return x; }
	int get_y() { return y; }
	int get_hp() { return hp; }
	int get_score() { return score; }
	String get_item() { return item; }

	bool get_done() { return done; }
	void set_done() { done = true; }

private:

	double stage_time;

	String name = U"";

	String pattern = U"";

	int x;

	int y;

	int hp;

	int score;

	String item = U"";

	bool done = false;
};
