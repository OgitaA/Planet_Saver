﻿#pragma once
#include"Catcher.hpp"

class Player {

public:

	Player();

	void update(double);
	void draw();

	RectF get_rect() { return rect; }
	double get_shot_cool_time() { return shot_cool_time; }
	void set_shot_cool_time(double v) { shot_cool_time = v; }
	void damage();
	String get_mode() { return mode; }

	void move();
	void limit_screen();
	void change_mode();

	void reset();

	int get_burn_gauge() { return burn_gauge; }
	int get_non_burn_gauge() { return non_burn_gauge; }
	int get_recycle_gauge() { return recycle_gauge; }

	bool get_miss() { return miss; }

	

	Catcher catcher;

	RectF get_catcher_hit_rect() { return catcher.get_hit_rect(); }

	void plus_catcher_item(String _v, String _type) { catcher.plus_item(_v, _type); }
	bool check_catcher_full() {return catcher.check_full_item(); }

	//キャッチャーのアイテムをエネルギーに変換
	void convert_catcher_item();

	void plus_burn_gauge();
	void plus_non_burn_gauge();
	void plus_recycle_gauge();

	void clear_catcher_item() { catcher.clear_item(); }


	//キャッチャー
	bool check_catcher_use() {

		if (catcher.get_operation()==true) {

			if (catcher.get_move_y() > 25) {

				return true;

			}
		}

		return false;
	}

	void catcher_error();


private:

	double d_time;

	RectF rect;

	double speed = 450;

	double shot_cool_time = 0;

	bool miss = false;

	double muteki_count = 0;

	String mode = U"";

	int burn_gauge = 0;
	int non_burn_gauge = 0;
	int recycle_gauge = 0;

	double burn_decrease_count = 0;
	double non_burn_decrease_count = 0;
	double recycle_decrease_count = 0;

	double catch_error_count = 0;

};
