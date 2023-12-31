﻿#pragma once
#include"Catcher.hpp"
#include"Option.hpp"
#include"Barrier.hpp"
#include"Gauge_Effect_Data.hpp"
#include"My_Effect.hpp"

# include <Siv3D.hpp> // Siv3D v0.6.12

class Player {

public:

	Player();

	void update(double);
	void draw();

	RectF get_rect() { return rect; }
	RectF get_hit_rect() { return hit_rect; }
	void update_hit_rect();
	double get_shot_cool_time() { return shot_cool_time; }
	void set_shot_cool_time(double v) { shot_cool_time = v; }
	void damage();
	String get_mode() { return mode; }

	void move();
	void limit_screen();
	void change_mode();

	//無敵かどうか
	bool get_muteki() {

		if (muteki_count > 0) {
			return true;
		}
		return false;
	}

	//リセット
	void reset();
	void reset_common();

	int get_burn_gauge() { return burn_gauge; }
	int get_non_burn_gauge() { return non_burn_gauge; }
	int get_recycle_gauge() { return recycle_gauge; }


    //キャッチャー

	Catcher catcher;

	RectF get_catcher_hit_rect() { return catcher.get_hit_rect(); }

	void plus_catcher_item(String _v, String _type) { catcher.plus_item(_v, _type); }
	bool check_catcher_full() { return catcher.check_full_item(); }

	//キャッチャーのアイテムをエネルギーに変換
	void convert_catcher_item();

	void plus_burn_gauge();
	void plus_non_burn_gauge();
	void plus_recycle_gauge();

	void clear_catcher_item() { catcher.clear_item(); }


	
	bool check_catcher_use() {

		if (catcher.get_operation() == true) {

			if (catcher.get_move_y() > 25) {

				return true;

			}
		}

		return false;
	}

	void catcher_error();


	//パワーアップのコントロール
	void control_power();
	void control_speed();


	//Option
	void plus_option();
	void minus_option();

	void control_option();
	void adjust_option();

	void set_option_memory();

	Array<Vec2> get_option_pos() {

		Array<Vec2> pos;

		for (auto& o : option) {

			pos.push_back(Vec2(o.get_x() + 28, o.get_y() + 28));
		}

		return pos;
	}

	size_t get_option_size() { return option.size(); }


	//バリア
	bool get_barrier_exist() { return barrier_exist; }
	Array<Triangle> get_barrier_triangle() { return barrier.get_moved_triangle(); }
    Triangle get_barrier_triangle_one(int _index) { return barrier.get_moved_triangle_one(_index); }

	void damage_barrier() { barrier.damage(); }
	void control_barrier();
	void plus_barrier();

	void draw_barrier();


	//文字エフェクト

	String get_moji_effect() {	return moji_effect;}
	String get_moji_effect_color() {return moji_effect_color;}

	void clear_moji_effect() { moji_effect = U""; }
	void clear_moji_effect_color() { moji_effect_color = U""; }


	//ゲージエフェクト
	void set_gauge_effect_data(String, int);

	size_t get_gauge_effect_data_size() { return gauge_effect_data.size(); }
	String get_gauge_effect_data_type(int index) {return  gauge_effect_data[index].type; }
	int get_gauge_effect_data_pos(int index) { return gauge_effect_data[index].pos; }

	void delete_gauge_effect_data() { gauge_effect_data.clear(); }

	//ミス
	void set_miss();
	void set_miss_gameover();
	bool get_miss() { return miss; }
	void update_miss();
	

	//MyEffect
	Array<My_Effect> my_effect;

	void update_my_effect();


	//自機以外の表示
	void draw_sub();

	//カウント
	int get_burn_count() { return burn_count; }
	int get_non_burn_count() { return non_burn_count; }
	int get_recycle_count() { return recycle_count; }

private:

	double d_time;

	RectF rect;

	RectF hit_rect;

	double speed = 450;

	double shot_cool_time = 0;

	double muteki_count = 0;

	String mode = U"";

	int burn_gauge = 0;
	int non_burn_gauge = 0;
	int recycle_gauge = 0;

	double catch_error_count = 0;

	//Option

	Array<Option> option;

	Array<Vec2> memory_pos;

	double old_x = 0;
	double old_y = 0;

	bool moved_x = false;
	bool moved_y = false;

	double option_adjust_x = 118 / 2 - 28;
	double option_adjust_y = 70 / 2 - 56 / 2;

	String moji_effect = U"";
	String moji_effect_color = U"";

	Array<Gauge_Effect_Data> gauge_effect_data;


	//バリア

	int barrier_count = 0;

	bool barrier_exist = false;

	Barrier barrier;

	


	//ミス

	bool miss = false;
	double miss_count = 0;
	int miss_scene = 0;

	double gameover_explode_count = 0;

	//無敵用フラッシュ
	bool muteki_flash = false;
	double muteki_flash_count = 0;


	//カウント
	int burn_count = 0;
	int non_burn_count = 0;
	int recycle_count = 0;
};
