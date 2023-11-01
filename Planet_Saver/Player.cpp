#include"Player.hpp"

Player::Player() {

	rect = Rect(1920 / 2, 1080 / 2, 119, 69);

	reset();

}

void Player::reset() {

	mode = U"burn";
	muteki_count = 0;

	barrier_count = 0;

	set_option_memory();

	clear_moji_effect();
	clear_moji_effect_color();

	delete_gauge_effect_data();

	//キャッチャーリセット
	catcher.reset();
	//キャッチャー位置調整
	catcher.first(rect.x, rect.y);

	//キャッチャーエラーリセット
	catch_error_count = 0;

	//キャッチャー使用可能
	catcher.set_miss(false);

	//オプション記憶
	set_option_memory();

	reset_common();
}

void Player::reset_common() {

	shot_cool_time = 0;

	burn_gauge = 0;
	non_burn_gauge = 0;
	recycle_gauge = 0;

	//オプション系
	option.clear();

	//バリア
	barrier_exist = false;
	barrier_count = 0;

}

void Player::update(double _d_time) {

	d_time = _d_time;

	
	//無敵
	if (muteki_count > 0) {

		muteki_count -= d_time;
	}

	//ショットクールタイム
	if (shot_cool_time > 0) {

		shot_cool_time -= d_time;
	}

	control_power();
	control_speed();


	//移動
	if (miss == false) {
		move();
	}

	//ヒットレクト
	update_hit_rect();

	//モードチェンジ
	change_mode();

	//キャッチャー
	catcher.update(d_time, rect.x, rect.y, mode);
	
	convert_catcher_item();

	if (catch_error_count > 0) {

		catch_error_count -= d_time;
		catcher.set_error(true);
	}
	else {
		catcher.set_error(false);
	}

	//オプション
	control_option();

	//バリア
	control_barrier();

	//ミス
	if (miss == true) {
		update_miss();
	}
}

void Player::draw() {

	if (barrier_exist == true) {

		barrier.draw();
	}

	
	for (auto& o : option) {

		o.draw();
	}

	catcher.draw();

	String image_name = U"player_" + mode;

	if (catch_error_count > 0) {

		image_name = U"player_error";
	}

	TextureAsset(image_name).draw(rect.x, rect.y);

	if (muteki_count > 0) {
		hit_rect.drawFrame(5, Palette::Red);
	}
}


void Player::move() {

	//オプション用
	moved_x = false;
	moved_y = false;

	old_x = rect.x;
	old_y = rect.y;

	//フレームあたりの移動速度
	double now_speed = speed * d_time;

	//低速移動
	/*
	if (KeyShift.pressed()) {
		now_speed *= 0.4;
	}*/

	/*
	//エラー中・速度低下
	if (catch_error_count > 0) {
		now_speed *= 0.5;
	}*/


	//斜め移動の速度制御

	int naname = 0;

	if (KeyUp.pressed() || KeyDown.pressed()) {
		if (KeyLeft.pressed() || KeyRight.pressed()) {
			naname = 1;
		}
	}

	if (naname == 1) {//斜めなら減速
		now_speed *= 0.7;
	}

	if (KeyUp.pressed()) {//上へ
		rect.y -= now_speed;
		
	}
	else if (KeyDown.pressed()) {//下へ
		rect.y += now_speed;
	}

	if (KeyLeft.pressed()) {//左へ
		rect.x -= now_speed;
	}
	else if (KeyRight.pressed()) {//右へ
		rect.x += now_speed;
	}

	limit_screen();

}

void Player::limit_screen() {

	//X座標画面
	if (rect.x < 0) {
		rect.x = 0;
	}
	else if (rect.x + rect.w > 1920) {
		rect.x = 1920 - rect.w;
	}

	//Y座標画面
	if (rect.y < 100) {
		rect.y = 100;
	}
	else if (rect.y + rect.h > 1080 - 45) {
		rect.y = 1080 - 45 - rect.h;
	}


	//オプション用

	double move_x = abs(rect.x - old_x);
	double move_y = abs(rect.y - old_y);

	if (move_x > 0) {
		moved_x = true;
	}
	if (move_y > 0) {
		moved_y = true;
	}

}

void Player::update_hit_rect() {

	hit_rect = RectF(rect.x + 15, rect.y + 15, 90, 40);
}


void Player::damage() {

	if (muteki_count <= 0) {

		if (recycle_gauge > 0) {
			recycle_gauge--;
		}
		else {
			miss = true;
		}


		muteki_count = 3;
	}

}


void Player::change_mode() {

	if (KeyShift.down()) {

		//キャッチャー起動中は使えない
		if (catcher.get_operation() == false) {

			if (mode == U"burn") {
				mode = U"non_burn";
			}
			else if (mode == U"non_burn") {
				mode = U"recycle";
			}
			else if (mode == U"recycle") {
				mode = U"burn";
			}
		}
	}
}

void Player::convert_catcher_item() {

	//キャッチャーにアイテムがある
	if (catcher.get_item_size() >= 1) {

		//キャッチャー上昇中
		if (catcher.get_status() == U"up") {

			//キャッチャーが自機と重なりかけたら処理
			if (catcher.get_move_y() <= 25) {

				//カウント
				int item_count = 0;

				//エラー
				bool error = false;


				for (size_t i = 0; i < catcher.get_item_size(); i++) {

					String type = catcher.get_item_type(i);

					if (mode == U"burn") {

						if (type == U"burn") {
							item_count++;
						}
						else {
							error = true;
						}
					}
					else if (mode == U"non_burn") {

						if (type == U"non_burn") {
							item_count++;
						}
						else {
							error = true;
						}
					}
					else if (mode == U"recycle") {

						if (type == U"recycle") {
							item_count++;
						}
						else
						{
							error = true;
						}
					}

				
				}


				//エラー発生
				if (error==true) {

					catcher_error();
				}
				//エラーがないならゲット
				else {

					for (int i = 0; i < item_count; i++) {

						if (mode==U"burn") {
							plus_burn_gauge();
						}
						else if (mode == U"non_burn") {
							plus_non_burn_gauge();
						}
						else if (mode == U"recycle") {
							plus_recycle_gauge();
						}
					}

				}

				//キャッチャーのアイテムデータをクリア
				clear_catcher_item();
			}
		
		}
	}

}

void Player::plus_burn_gauge() {

	if (burn_gauge < 5) {
		moji_effect = U"POWER UP";
		moji_effect_color = U"Red";

		burn_gauge++;

		plus_option();

		set_gauge_effect_data(U"burn", burn_gauge);
	}


	

	if (burn_gauge >= 5) {
		burn_gauge = 5;
	}
}

void Player::plus_non_burn_gauge() {

	if (non_burn_gauge < 5) {
		moji_effect = U"SPEED UP";
		moji_effect_color = U"Blue";

		non_burn_gauge++;

		set_gauge_effect_data(U"non_burn", non_burn_gauge);
	}

	

	if (non_burn_gauge >= 5) {
		non_burn_gauge = 5;
	}
}

void Player::plus_recycle_gauge() {

	if (recycle_gauge < 5) {
		moji_effect = U"BARRIER UP";
		moji_effect_color = U"Green";

		recycle_gauge++;

		plus_barrier();

		set_gauge_effect_data(U"recycle", recycle_gauge);
	}

	

	if (recycle_gauge >= 5) {
		recycle_gauge = 5;
	}
}

void Player::set_gauge_effect_data(String _name, int _v) {

	gauge_effect_data.push_back(Gauge_Effect_Data(_name, _v));
}


void Player::catcher_error() {

	catch_error_count = 3;

}

void Player::control_power() {

}

void Player::control_speed() {

	if (non_burn_gauge == 0) {
		speed = 300;
	}
	else if (non_burn_gauge == 1) {
		speed = 400;
	}
	else if (non_burn_gauge == 2) {
		speed = 450;
	}
	else if (non_burn_gauge == 3) {
		speed = 500;
	}
	else if (non_burn_gauge == 4) {
		speed = 550;
	}
	else if (non_burn_gauge == 5) {
		speed = 600;
	}

}

void Player::set_option_memory() {

	memory_pos.clear();

	for (int i = 0; i < 100; i++) {

		memory_pos.push_back(Vec2{ rect.x + option_adjust_x,rect.y + option_adjust_y });
	}

}


void Player::plus_option() {

	if (option.size() < 5) {

		option.push_back(Option(rect.x + option_adjust_x, rect.y + option_adjust_y));

		adjust_option();
	}
}

void Player::plus_barrier() {

	if (barrier_count < 5) {
		barrier_count++;
	}

	if (barrier_exist == false) {
		barrier_exist = true;
	}


}

void Player::control_option() {

	if (moved_x == true) {

		memory_pos[99].x = rect.x + option_adjust_x;

		for (size_t m = 0; m < memory_pos.size() - 1; m++) {

			memory_pos[m].x = memory_pos[m + 1].x;			
		}

	}

	if (moved_y == true) {

		memory_pos[99].y = rect.y +option_adjust_y;

		for (size_t m = 0; m < memory_pos.size() - 1; m++) {

			memory_pos[m].y = memory_pos[m + 1].y;
		}

	}

	adjust_option();
}

void Player::adjust_option() {

	for (size_t o = 0; o < option.size(); o++) {

		if (o == 0) {
			option[o].set_pos_x(memory_pos[85].x);
			option[o].set_pos_y(memory_pos[85].y);
		}
		else if (o == 1) {
			option[o].set_pos_x(memory_pos[75].x);
			option[o].set_pos_y(memory_pos[75].y);
		}
		else if (o == 2) {
			option[o].set_pos_x(memory_pos[65].x);
			option[o].set_pos_y(memory_pos[65].y);
		}
		else if (o == 3) {
			option[o].set_pos_x(memory_pos[55].x);
			option[o].set_pos_y(memory_pos[55].y);
		}
		else if (o == 4) {
			option[o].set_pos_x(memory_pos[45].x);
			option[o].set_pos_y(memory_pos[45].y);
		}
	}
}

void Player::control_barrier() {

	barrier.update(d_time, rect.x + rect.w / 2, rect.y + rect.h / 2);

	//バリア削除

	if (barrier.get_delete() == true) {
		barrier_count--;
		barrier.set_renew();
	}

	//バリア有無
	if (barrier_count <= 0) {
		barrier_exist = false;
	}
	else {
		barrier_exist = true;
	}

}

void Player::set_miss() {

	miss = true;

	//キャッチャーを起動できなくする
	catcher.set_miss(true);

	//無敵付与
	muteki_count = 5;
}

//ゲームオーバー用のミス
void Player::set_miss_gameover() {

	miss = true;

	//キャッチャーを起動できなくする
	catcher.set_miss(true);

	//無敵付与
	muteki_count = 5;

	//ゲームオーバー用のシーンへ
	miss_scene = 100;
}

void Player::update_miss() {

	miss_count += d_time;

	if (miss_scene == 0) {

		//爆発エフェクト用
		if (miss_count >= 1) {

			miss_scene++;
		}

	}
	else if (miss_scene == 1) {

		//自動復帰用
		rect.x = -200;
		rect.y = 1080 / 2 - rect.h / 2;

		//キャッチャーリセット
		catcher.reset();
		//キャッチャー位置調整
		catcher.first(rect.x, rect.y);

		//キャッチャーエラーリセット
		catch_error_count = 0;

		//プレイヤーリセット
		reset_common();

		miss_scene++;
	}
	else if (miss_scene == 2) {

		//移動

		rect.x += 400 * d_time;

		//キャッチャー位置調整
		catcher.first(rect.x, rect.y);

		if (rect.x >= 400) {

			//オプション処理
			set_option_memory();

			//終了処理
			miss = false;
			miss_scene = 0;
			miss_count = 0;
			catcher.set_miss(false);
		}
	}


	//ゲームオーバー用のミス

	if (miss_scene == 100) {

		//爆発エフェクト用
		if (miss_count >= 1) {

			miss_scene++;
		}

	}
	else if (miss_scene == 101) {

		if (miss_count > 3) {

			//終了処理
			miss = false;
			miss_scene = 0;
			miss_count = 0;

			Print << U"pass";
		}
	}


}
