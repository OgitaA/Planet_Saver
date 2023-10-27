#pragma once

#include"Player.hpp"
#include"Player_Bullet.hpp"
#include"Emerge_Enemy.hpp"
#include"Enemy.hpp"
#include"Enemy_Bullet.hpp"
#include"Item.hpp"
#include"Back.hpp"
#include"Back_Object_Data.hpp"
#include"Back_Object.hpp"
#include"Stage_Select_Box.hpp"
#include"Emerge_Item.hpp"


class Game {

public:

	int main_scene = 0;

	void set_up();

	void update();
	void draw();

	//Setup
	void set_screen();
	void set_data();
	void set_stage_select_box();
	void make_stage_select_box(int, String);
	void load_image();
	void load_music();
	void load_font();
	void debug_data();

	//Common
	int stage = 1;
	int clear_stage = 3;

	void draw_indention(Font, String, int, int, int);

	//Change_Scene
	bool change_scene_process = false;
	int change_scene_scene = 0;
	double change_scene_alpha = 0;
	double change_scene_count = 0;

	int change_scene_go_scene = 0;

	void change_scene(int);
	void change_scene_title();
	void change_scene_battle();
	void change_scene_stage_select();

	void update_change_scene();
	void draw_change_scene();;



	//Battle

	double stage_time = 0;
	int score = 0;
	int remain = 3;

	void update_battle();
	void draw_battle();



	Player player;
	Array<Player_Bullet> player_bullet;
	Array<Emerge_Enemy> emerge_enemy;
	Array<Enemy> enemy;
	Array<Enemy_Bullet> enemy_bullet;
	Array<Emerge_Item> emerge_item;
	Array<Item> item;
	Back back;
	Array<Back_Object_Data> back_object_data;
	Array<Back_Object> back_object;


	//Player
	void make_player_shot();
	void make_player_bullet(String, double, double, double, int, double);

	void delete_player_bullet();

	void update_player_bullet(double);
	void draw_player_bullet();

	void miss();

	//Enemy
	void make_enemy();
	void update_enemy(double);
	void load_enemy_data(int);
	void draw_enemy();
	void delete_enemy();

	void make_enemy_shot();
	void make_enemy_bullet(String, double, double, double, int, double);

	void delete_enemy_bullet();

	void update_enemy_bullet(double);
	void draw_enemy_bullet();

	void player_bullet_vs_enemy();
	void player_vs_enemy();

	//Item
	void make_item();
	void update_item(double);
	void draw_item();
	void make_item(String, int, int);

	void player_catcher_vs_item();

	void delete_item();

	//Back
	void update_back(double);
	void draw_back();
	void update_back_object(double);
	void draw_back_object();

	//UI
	void draw_UI();

	//Stage

	double stage_scroll_speed = 100;
	double stage_scroll_speed_2 = 100;

	double back_count;
	void make_stage(int);
	void make_back_object_data(String, int, double);
	void make_back_object_data(String, int, double, String);
	void make_back_object_data(String, int, double, int);
	void make_back_object(String, int);
	void make_back_object(String, int, String);

	void update_stage(double);

	void set_stage_1();
	void set_stage_2();
	void set_stage_3();


	//Title

	int title_scene = 0;
	int title_cur = 0;
	double title_cur_interval = 0;

	void update_title();
	void draw_title();

	//Stage_Select

	int stage_select_cur = 0;
	double stage_select_cur_interval = 0;

	void update_stage_select();
	void draw_stage_select();
	Array<Stage_Select_Box> stage_select_box;

	//GameOver
	void update_gameover();
	void draw_gameover();



	//Menu
	void update_menu();
	void draw_menu();

	//Setting
	void update_setting();
	void draw_setting();

	//Music
	Array<String> bgm;
	Array<String> se;

	int bgm_volume = 5;
	int se_volume = 5;

	Array<int> se_will;
	Array<double> se_lock;

	void play_se(int);
	void update_se_main(double);
	void play_se_main();
	void play_bgm(int);
	void stop_bgm();

	void change_bgm_volume();
	void change_se_volume();
};
