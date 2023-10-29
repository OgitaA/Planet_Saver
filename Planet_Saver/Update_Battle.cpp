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




	//敵削除
	delete_enemy();

	//プレイヤーと敵
	player_vs_enemy();

	//ミス判定・処理
	miss();

	//ステージ更新
	update_stage(d_time);

	//背景更新
	update_back(d_time);

	//背景モノ更新
	update_back_object(d_time);

	
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

	if (b_x<-200 or b_x>(1920 + 200) or b_y < -200 or b_y>1080 + 200) {
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
				int y = e.get_y();
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
				int y = i.get_y();

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


	for (auto& e : enemy) {

		//当たった時
		if (b_c.intersects(e.get_rect())) {

			e.damage(b_p);

			return true;
		}
	}

	return false;

		});
}

void Game::delete_enemy() {

	//撃破

	enemy.remove_if([&](Enemy e) {

		if (e.get_hp() <= 0) {

			make_item(e.get_item(), e.get_rect().x, e.get_rect().y);

			plus_score(e.get_score());

			return true;
		}
		else {
			return false;
		}


	});

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

	for (auto& e : enemy) {

		RectF p_r = player.get_rect();
		RectF e_r = e.get_rect();


		if (p_r.intersects(e_r)) {
			player.damage();
		}
	}
}

void Game::miss() {

	if (player.get_miss() == true) {

		//残機減らす
		remain--;

		//残機が0ならゲームオーバーへ
		if (remain <= 0) {

		}
	}
}


void Game::update_enemy(double _d_time) {

	for (auto& e : enemy) {
		e.update(_d_time);
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

void Game::update_back(double _d_time) {

	back.update(_d_time);
}

void Game::update_back_object(double _d_time) {

	//ステージスクロール
	double scroll_speed = stage_scroll_speed * _d_time;
	double scroll_speed_2 = stage_scroll_speed_2 * _d_time;

	for (auto& b : back_object) {

		if (b.get_layer() == 0) {
			b.update(scroll_speed);
		}
	}

	for (auto& b : back_object) {

		if (b.get_layer() == 1) {
			b.update(scroll_speed_2);
		}
	}
}


void Game::plus_score(int v) {

	score += v;

	if (score > 99999999) {
		score = 99999999;
	}
}
