#pragma once

#include"Player.hpp"
#include"Player_Bullet.hpp"
#include"Emerge_Enemy.hpp"
#include"Enemy.hpp"
#include"Enemy_Bullet.hpp"
#include"Item.hpp"
#include"Back_Ground.hpp"
#include"Back_Object_Data.hpp"
#include"Back_Object.hpp"
#include"Stage_Select_Box.hpp"
#include"Emerge_Item.hpp"
#include"Moji_Effect.hpp"
#include"My_Effect.hpp"
#include"Gauge_Effect.hpp"
#include"Gauge_Effect_Data.hpp"


#include"White_Effect.hpp"


#include"Develop_Select_Rect.hpp"
#include"Develop_Kind_Select_Rect.hpp"

class Game {

public:

	String main_scene = U"";


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
	void set_shader();
	void debug_data();

	//Common
	int stage = 1;
	int clear_stage = 0;

	void draw_indention(Font, String, int, int, int);

	//Change_Scene
	bool change_scene_process = false;
	int change_scene_scene = 0;
	double change_scene_alpha = 0;
	double change_scene_count = 0;

	String change_scene_go_scene = U"";

	void change_scene(String);
	void change_scene_title();
	void change_scene_battle();
	void change_scene_stage_select();
	void change_scene_gameover();

	void update_change_scene();
	void draw_change_scene();;



	//Battle

	double stage_time = 0;
	int score = 0;
	int remain = 3;

	void update_battle();
	void draw_battle();

	void load_stage_data(int);

	void plus_score(int);

	void go_stage_clear(double);
	void go_gameover();

	Player player;
	Array<Player_Bullet> player_bullet;
	Array<Emerge_Enemy> emerge_enemy;
	Array<Enemy> enemy;
	Array<Enemy_Bullet> enemy_bullet;
	Array<Emerge_Item> emerge_item;
	Array<Item> item;
	Back_Ground back_ground;
	Array<Back_Object_Data> back_object_data;
	Array<Back_Object> back_object;
	Array<My_Effect> my_effect;
	Array<Moji_Effect> moji_effect;
	Array<Gauge_Effect> gauge_effect;


	//Player
	void make_player_shot();
	void make_player_bullet(String, double, double, double, int, double,double);

	void delete_player_bullet();

	void update_player_bullet(double);
	void draw_player_bullet();

	void miss();

	//Enemy
	void make_enemy();
	void update_enemy(double);
	void draw_enemy();
	void delete_enemy();

	void make_enemy_shot();
	void make_enemy_bullet(String, double, double,int, double,double);
	double get_angle_e_to_p(RectF);

	void delete_enemy_bullet();

	void update_enemy_bullet(double);
	void draw_enemy_bullet();

	void player_bullet_vs_enemy();
	void player_vs_enemy();
	void player_vs_enemy_bullet();
	void player_barrier_enemy_bullet();

	void make_enemy_by_enemy();
	

	//shader

	PixelShader psWhite;

	ConstantBuffer<WhiteEffectConstants> cbWhite;

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

	//My_Effect
	void update_my_effect(double);
	void draw_my_effect_back();
	void draw_my_effect_front();
	void delete_my_effect();

	//Explode
	

	//Moji_Effect
	void make_moji_effect();
	void delete_moji_effect();
	void update_moji_effect(double);
	void draw_moji_effect();

	//Gauge_Effect
	void make_gauge_effect();
	void delete_gauge_effect();
	void update_gauge_effect(double);
	


	//UI
	void draw_UI();

	//Stage

	double stage_scroll_speed_layer_0 = 100;
	double stage_scroll_speed_layer_1 = 100;
	double stage_scroll_speed_layer_2 = 100;
	double stage_scroll_speed_layer_3 = 100;

	double stage_up_scroll_speed = 50;

	double back_count;
	void make_stage(int);
	

	void make_back_object_data(String,String,int,int,int,double);
	void make_back_object_data(String, String, int, int, int, double, int);

	

	void make_back_object(String, String, int, int, int);

	void update_stage(double);

	void set_stage_1();
	void set_stage_2();
	void set_stage_3();

	void set_back_object_first();


	//Title

	int title_scene = 0;
	int title_cur = 0;
	double title_cur_interval = 0;
	bool title_once = false;

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

	bool gameover_once = false;


	//StageClear
	void update_stageclear();
	void draw_stageclear();

	bool stage_clear_flag = false;
	double stage_clear_count = 0;

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

	void start_bgm(String);

	//Gameover
	int gameover_cur = 0;


	//Develop

	String develop_image_name = U"";
	String develop_editing_text = U"";

	Array<Develop_Select_Rect> develop_select_rect;
	Array<Develop_Kind_Select_Rect> develop_kind_select_rect;

	String develop_shape = U"Rect";
	String develop_kind = U"item";

	int develop_rect_scene = 0;
	Vec2 develop_rect_start = { 0,0 };
	Vec2 develop_rect_end = { 0,0 };

	int develop_quad_scene = 0;
	Vec2 develop_quad_1 = { 0,0 };
	Vec2 develop_quad_2 = { 0,0 };
	Vec2 develop_quad_3 = { 0,0 };
	Vec2 develop_quad_4 = { 0,0 };

	int develop_circle_x = 0;
	int develop_circle_y = 0;
	int develop_circle_r = 0;

	void set_up_develop();
	void update_develop();
	void draw_develop();
};
