#pragma once
#include"My_Effect.hpp"

# include <Siv3D.hpp> // Siv3D v0.6.12



class Enemy {

public:

	Enemy(String, String, int, int, int, int, String);

	Enemy(String, String, int, int, int, int, String, double);

	void update(double);
	void draw();

	void each();
	void damage(int);
	int get_hp() { return hp; }
	double get_count() { return count; }
	String get_item() { return item; }

	Array<int> get_make_bullet() { return make_bullet; }
	void set_make_bullet_done() { make_bullet.clear(); }
	void plus_make_bullet(int v) { make_bullet.push_back(v); }


	void move();

	void straight_move();

	void curve_move();
	void shot_straight_move();
	void shot_straight_three_move();

	void shot_straight_fast_move();

	void up_left_move();

	void maker_move();

	void slow_shot_three_move();

	void track_move();

	void bomb_move();
	void bomb_2_move();
	void bomb_3_move();

	void bomb_g_move();
	void bomb_g_2_move();
	void bomb_g_3_move();

	void shot_eternal_move();

	void support_move();
	void support_2_move();
	void support_3_move();

	void support_g_move();
	void support_g_2_move();


	void support_g_3_move();

	void boss_1_move();
	void boss_2_move();
	void boss_3_move();

	void shot_g_straight_three_move();

	int get_score() { return score; }

	String get_shape() { return shape; }
	RectF get_rect() { return rect; }
	Circle get_circle();
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

	bool get_boss() { return boss; }
	void set_boss_broken() { boss_broken = true; }
	bool get_boss_broken() { return boss_broken; }


	//Move_Common
	void next_scene();
	void next_scene_b();
	void change_move_scene(int);

	//MyEffect

	void update_my_effect();

	//MakeEnemy
	Array<int> get_make_enemy() { return make_enemy; }
	void set_make_enemy_done() { make_enemy.clear(); }
	void plus_make_enemy(int v) { make_enemy.push_back(v); }

	//爆発サイズ
	int get_explode_size() { return explode_size; }

	//追跡用
	void update_data(double v) {
		track_angle = v;
	}

	//自爆用
	void set_bomb_death() { bomb_death = true; }
	bool get_bomb_death() { return bomb_death; }

	//ボス
	bool get_boss_armer() { return boss_armer; }

private:

	double d_time;

	String name = U"";

	String shape = U"";

	RectF rect;

	Quad quad;

	Circle circle;

	double speed = 100;

	double speed_2 = 100;

	double speed_3 = 100;

	String pattern = U"";

	int hp;

	int score = 0;

	String item = U"";

	double count = 0;

	//maker

	double maker_y = 0;


	//MakeBullet
	Array<int> make_bullet;


	//shader

	bool white = false;

	double white_count = 0;

	//Move_V

	double start_x = 0;
	double start_y = 0;

	int move_scene = 0;
	int move_scene_b = 0;

	double move_count = 0;
	double move_count_b = 0;

	double move_v_0 = 0;
    double move_v_1 = 0;

	double move_angle = 0;


	


	//ボス

	bool boss = false;
	bool boss_broken = false;

	double boss_broken_count = 0;

	bool boss_armer = false;

	//MyEffect
	Array<My_Effect> my_effect;

	//エネミー生成
	Array<int> make_enemy;

	//爆発サイズ
	int explode_size = 1;


	//追跡
	double track_angle = 0;

	double track_decide_angle = 0;

	//自爆用
	bool bomb_death = false;

	
};

