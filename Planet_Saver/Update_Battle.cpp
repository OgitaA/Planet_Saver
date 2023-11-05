#include"Game.hpp"

void Game::update_battle() {

	double d_time = Scene::DeltaTime();

	stage_time += d_time;

	//敵生成
	make_enemy();

	//アイテム生成
	make_item();

	//プレイヤー更新
	player.update(d_time);

	//敵更新
	update_enemy(d_time);

	//敵から敵を生成
	make_enemy_by_enemy();

	//プレイヤーと敵
	player_vs_enemy();

	//アイテム
	update_item(d_time);

	//プレイヤーvsアイテム
	player_catcher_vs_item();

	//アイテム削除
	delete_item();

	//back_object更新
	update_back_object(d_time);


	//プレイヤーショット生成
	make_player_shot();

	//プレイヤー弾・更新
	update_player_bullet(d_time);

	//プレイヤー弾・画面外削除
	delete_player_bullet();

	//プレイヤー弾vsエネミー
	player_bullet_vs_enemy();


	//エネミーショット生成
	make_enemy_shot();

	//エネミー弾・更新
	update_enemy_bullet(d_time);

	//エネミー弾・画面外削除
	delete_enemy_bullet();

	//エフェクト更新
	update_my_effect(d_time);

	//エネミー弾vsプレイヤー
	player_vs_enemy_bullet();

	//エネミー弾vsプレイヤーバリア
	player_barrier_enemy_bullet();

	//エフェクト削除
	delete_my_effect();

	//文字エフェクト生成
	make_moji_effect();

	//文字エフェクト更新
	update_moji_effect(d_time);

	//文字エフェクト削除
	delete_moji_effect();

	//ゲージエフェクト生成
	make_gauge_effect();

	//ゲージエフェクト更新
	update_gauge_effect(d_time);

	//ゲージエフェクト削除
	delete_gauge_effect();

	//敵削除
	delete_enemy();

	//ステージ更新
	update_stage(d_time);

	//背景更新
	update_back(d_time);

	//背景モノ更新
	update_back_object(d_time);

	//ゲームオーバーへ
	go_gameover();

	//ゲームクリアへ
	go_stage_clear(d_time);

	//Print << U"back_object_size::" << back_object.size();
}

void Game::update_player_bullet(double _d_time) {

	for (auto& b : player_bullet) {
		b.update(_d_time);
	}

}

void Game::delete_player_bullet() {

	player_bullet.remove_if([&](Player_Bullet b) {

		double b_x = b.get_circle().x;
	    double b_y = b.get_circle().y;

	if (b_x<-80 or b_x>(1920 + 80) or b_y < -80 or b_y>1080 + 80) {
		return true;
	}
	else {
		return false;
	}

		});
}

void Game::delete_enemy_bullet() {

	enemy_bullet.remove_if([&](Enemy_Bullet b) {

		double b_x = b.get_circle().x;
	    double b_y = b.get_circle().y;

	if (b_x<-200 or b_x>(1920 + 200) or b_y < -200 or b_y>1080 + 200) {
		return true;
	}
	else {
		return false;
	}

		});
}

void Game::make_enemy() {

	for (auto& e : emerge_enemy) {

		//まだ登場していない
		if (e.get_done() == false) {

			double time = e.get_stage_time();


			//時間
			if (stage_time >= time) {

				String name = e.get_name();
				String pattern = e.get_pattern();
				int x = e.get_x();

				//UIフレーム分調整
				int y = e.get_y() + 100;

				int hp = e.get_hp();
				int score = e.get_score();
				String item = e.get_item();

				enemy.push_back(Enemy(name, pattern, x, y, hp, score, item));

				e.set_done();
			}

		}
	}
}

void Game::make_item() {

	for (auto& i : emerge_item) {

		//まだ登場していない
		if (i.get_done() == false) {

			double time = i.get_stage_time();

			//時間
			if (stage_time >= time) {

				String name = i.get_name();
				int x = i.get_x();
				int y = i.get_y() + 100;

				item.push_back(Item(name, x, y));

				i.set_done();
			}
		}

	}
}


void Game::update_enemy_bullet(double _d_time) {

	for (auto& e : enemy_bullet) {
		e.update(_d_time);
	}

}


void Game::player_bullet_vs_enemy() {

	

		player_bullet.remove_if([&](Player_Bullet b) {

			double b_x = b.get_circle().x;
		double b_y = b.get_circle().y;

		Circle b_c = b.get_circle();
		int b_p = b.get_power();

		bool bullet_delete = false;

		for (auto& e : enemy) {

			//弾が削除済みでない
			if (bullet_delete == false) {

				//敵に当たったか
				bool hit = false;

				//ボス用
				if (e.get_boss_broken() == false) {

					if (e.get_boss_armer() == false) {

						String shape = e.get_shape();

						if (shape == U"Quad") {
							if (b_c.intersects(e.get_quad())) {
								hit = true;
							}
						}
						else if (shape == U"Circle") {
							if (b_c.intersects(e.get_circle())) {
								hit = true;
							}
						}
						else if (shape == U"Rect") {
							if (b_c.intersects(e.get_rect())) {
								hit = true;
							}
						}
					}
				}

				//当たった時
				if (hit == true) {

					e.damage(b_p);

					bullet_delete = true;
				}
			}
		}


		//敵に当たっていたなら弾削除
		if (bullet_delete == true) {
			return true;
		}

		return false;

			});
	
}

void Game::delete_enemy() {

	//撃破

	enemy.remove_if([&](Enemy e) {

		if (e.get_hp() <= 0) {

			if (e.get_boss() == false) {

				String item_name = e.get_item();

				if (item_name != U"no") {

					make_item(e.get_item(), e.get_rect().x, e.get_rect().y);

				}

				plus_score(e.get_score());

				double center_x = e.get_center_x();
				double center_y = e.get_center_y();

				int explode_size = e.get_explode_size();

				if (explode_size == 1) {

					my_effect.push_back(My_Effect(U"explode", center_x, center_y));

				}
				else if (explode_size == 2) {

					my_effect.push_back(My_Effect(U"explode_custom_1.5", center_x, center_y));
				}
				else if (explode_size == 3) {

					my_effect.push_back(My_Effect(U"explode_custom_2", center_x, center_y));
				}
				//Print << U"center_x::" << center_x;
				//Print << U"center_y::" << center_y;

				return true;

			}
			else {
				return false;
			}
		
		}
		else {
			return false;
		}


	});


	//ボスの場合破壊フラグ
	for (auto& e : enemy) {

		//ボスなら
		if (e.get_boss() == true) {

			if (e.get_hp() <= 0) {
				e.set_boss_broken();
				stage_clear_flag = true;
			}
		}
	}

	//時間退場

	enemy.remove_if([&](Enemy e) {

		//ボスかどうか
		if (e.get_boss() == false) {

			//15秒立っているなら退場
			if (e.get_count() >= 15) {
				return true;

			}
			else {
				return false;
			}


		}
		else {
			return false;
		}


	});
}

void Game::make_item(String _name, int _x, int _y) {

	item.push_back(Item(_name, _x, _y));
}

void Game::delete_item() {

	item.remove_if([&](Item i) {

		if (i.get_rect().x + i.get_rect().w < -100) {

			return true;
		}
		else {

			return false;
		}

	});
}


void Game::player_vs_enemy() {

	if (stage_clear_flag == false) {

		bool hit = false;

		for (auto& e : enemy) {

			RectF p_r = player.get_hit_rect();
			RectF e_r = e.get_rect();



			String shape = e.get_shape();

			if (shape == U"Quad") {

				if (p_r.intersects(e.get_quad())) {
					hit = true;
				}
			}
			else if (shape == U"Circle") {

				if (p_r.intersects(e.get_circle())) {
					hit = true;
				}
			}
			else if (shape == U"Rect") {

				if (p_r.intersects(e.get_rect())) {
					hit = true;
				}
			}



		}

		if (hit == true) {
			miss();
		}

	}
}


void Game::player_vs_enemy_bullet() {

	if (stage_clear_flag == false) {

		//バリアがない
		if (player.get_barrier_exist() == false) {

			enemy_bullet.remove_if([&](Enemy_Bullet e) {

				if (player.get_hit_rect().intersects(e.get_circle())) {



					miss();



					return true;
				}
				else {

					return false;
				}

			});

		}
	}
}

void Game::player_barrier_enemy_bullet() {

	if (stage_clear_flag == false) {

		//バリアが存在する
		if (player.get_barrier_exist() == true) {

			enemy_bullet.remove_if([&](Enemy_Bullet e) {


				for (size_t b = 0; b < player.get_barrier_triangle().size(); b++) {

					if (player.get_barrier_triangle_one(b).intersects(e.get_circle())) {

						player.damage_barrier();
						return true;
					}


				}

			return false;


			});
		}
	}
}

//他の被弾系関数から呼ばれる
void Game::miss() {

	//プレイヤーが無敵でないなら
	if (player.get_muteki() == false) {

			//プレイヤーがまだミスでないなら(これからミス処理)
			if (player.get_miss() == false) {

				//残機減らす
				remain--;

				if (remain > 0) {
					player.set_miss();
				}
				else {
					//プレイヤーにミスの処理（復帰なし）
					player.set_miss_gameover();
				}

				//文字エフェクト削除
				moji_effect.clear();

				//ゲージエフェクト削除
				gauge_effect.clear();

			}
	}
}

void Game::go_gameover() {

	//残機がない
	if (remain <= 0) {

		//プレイヤーの処理が終わった

		if (player.get_miss() == false) {
			main_scene = U"gameover";
		}
	}
}

void Game::update_enemy(double _d_time) {

	for (auto& e : enemy) {
		e.update(_d_time);

    //プレイヤーの位置を渡す

		double angle = ToRadians(get_angle_e_to_p(e.get_rect()));

		e.update_data(angle);

	}

	


}


void Game::update_item(double _d_time) {

	for (auto& i : item) {
		i.update(_d_time);
	}
}

void Game::player_catcher_vs_item() {

	if (player.check_catcher_use() == true) {

		item.remove_if([&](Item i) {

            //キャッチャーに触れている

			bool hit = false;
		    String shape = i.get_shape();

			RectF p_rect = player.get_catcher_hit_rect();


			if (shape == U"Rect") {

				if (p_rect.intersects(i.get_rect())) {
					hit = true;
				}
			}
			else if(shape == U"Circle") {

				if (p_rect.intersects(i.get_rect())) {
					hit = true;
				}
			}
			else if (shape == U"Quad") {

				if (p_rect.intersects(i.get_quad())) {
					hit = true;
				}
			}


			if (hit == true) {

				String name = i.get_name();
				String type = i.get_type();

				//キャッチャーに空きがある
				if (player.check_catcher_full() == false) {

					player.plus_catcher_item(name, type);

					return true;
				}
				else {
					return false;
				}


			}
			else {
				return false;
			}

		});

	}



}


void Game::update_my_effect(double _d_time) {

	for (auto& e : my_effect) {
		e.update(_d_time);
	}
}

void Game::delete_my_effect() {

	my_effect.remove_if([&](My_Effect e) {

		if (e.get_delete() == true) {
			return true;
		}

	return false;


	});
}


void Game::make_moji_effect() {

	//Player文字関連
	if (player.get_moji_effect() != U"") {

		String text = player.get_moji_effect();

		int x = player.get_rect().x + 120 / 2;
		int y = player.get_rect().y - 25;

		String color = player.get_moji_effect_color();

		moji_effect.push_back(Moji_Effect(text,x,y,color));


		player.clear_moji_effect();
		player.clear_moji_effect_color();
	}
}

void Game::delete_moji_effect() {

	moji_effect.remove_if([&](Moji_Effect e) {

		if (e.get_delete() == true) {
			return true;
		}
	
		return false;
		

	});
}

void Game::update_moji_effect(double _d_time) {

	for (auto& e : moji_effect) {
		e.update(_d_time);
	}
}

void Game::update_back(double _d_time) {

	back_ground.update(_d_time);
}

void Game::update_back_object(double _d_time) {

	//ステージスクロール
	double scroll_speed_0 = stage_scroll_speed_layer_0 * _d_time;
	double scroll_speed_1 = stage_scroll_speed_layer_1 * _d_time;
	double scroll_speed_2 = stage_scroll_speed_layer_2 * _d_time;
	double scroll_speed_3 = stage_scroll_speed_layer_3 * _d_time;


	double up_scroll_speed = stage_up_scroll_speed * _d_time;

	for (auto& b : back_object) {

		String direction = b.get_direction();
		int layer = b.get_layer();


		if (direction == U"left") {

			if (layer == 0) {
				b.update(scroll_speed_0);
			}
			else if (layer == 1) {
				b.update(scroll_speed_1);
			}
			else if (layer == 2) {
				b.update(scroll_speed_2);
			}
			else if (layer == 3) {
				b.update(scroll_speed_3);
			}
		}
		else if (direction == U"up") {

			b.update(scroll_speed_0, up_scroll_speed);
		}
		

		
	}

}


void Game::plus_score(int v) {

	score += v;

	if (score > 99999999) {
		score = 99999999;
	}
}

void Game::make_gauge_effect() {

	for (size_t e = 0; e < player.get_gauge_effect_data_size(); e++) {

		String type = player.get_gauge_effect_data_type(e);
		int pos = player.get_gauge_effect_data_pos(e);

		gauge_effect.push_back(Gauge_Effect(type,pos));

	}

	player.delete_gauge_effect_data();
}

void Game::delete_gauge_effect() {

	gauge_effect.remove_if([&](Gauge_Effect e) {

		if (e.get_delete() == true) {
			return true;
		}

	return false;


    });
}

void Game::update_gauge_effect(double _d_time) {

	for (auto& e : gauge_effect) {
		e.update(_d_time);
	}
}



void Game::go_stage_clear(double _d_time) {

	if (stage_clear_flag == true) {

		stage_clear_count += _d_time;

		if (stage_clear_count >= 5) {

			//最後にボスのスコアを加算
			int boss_score = 0;

			for (auto& e : enemy) {
				if (e.get_boss() == true) {
					boss_score = e.get_score();
				}
			}

			score += boss_score;

			main_scene = U"stageclear";
		}
	}
}





