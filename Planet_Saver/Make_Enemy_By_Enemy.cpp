#include"Game.hpp"

void Game::make_enemy_by_enemy() {

	class Will_Emerge {

	public:

		Will_Emerge(String _name,String _pattern,int _x,int _y,int _hp,int _score,String _item,double _maker_y) {

			name = _name;
			pattern = _pattern;
			x = _x;
			y = _y;
			hp = _hp;
			score = _score;
			item = _item;
			maker_y = _maker_y;
		}

		 String name = U"normal";
		 String pattern = U"normal";
		 int x = 0;
		 int y = 0;
		 int hp = 10;
		 int score = 100;
		 String item = U"no";
		 double maker_y = 0;

	};

	Array<Will_Emerge> will_emerge;

	if (stage_clear_flag == false) {

		for (auto& e : enemy) {

			if (e.get_make_enemy().size() >= 1) {



				for (size_t m_e = 0; m_e < e.get_make_enemy().size(); m_e++) {

					int type = e.get_make_enemy()[m_e];

					RectF e_r = e.get_rect();

					double e_x = e_r.x + e_r.w / 2;
					double e_y = e_r.y + e_r.h / 2;

					double angle = 180;


					//data
					String name = U"rumba";
					String pattern = U"normal";
					int x = e_x;
					int y = e_y;
					int hp = 10;
					int score = 100;
					String item = U"no";

					//各種生成
					if (type == 0) {

						name = U"rumba_baby";
						pattern = U"up_left";

						hp = 10;
						score = 100;



						will_emerge.push_back(Will_Emerge(name, pattern, x, y, hp, score, item, y));
					}
					//ステージ１ボス
					else  if (type == 1) {

						name = U"rumba_support";
						pattern = U"support";

						hp = 50;
						score = 0;


						x = 1920;
						int y_a = 167 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));

						int y_b = y + 767 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, y_b, y, hp, score, item, y));

					}
					else if (type == 2) {

						name = U"rumba_support";
						pattern = U"support";

						hp = 50;
						score = 0;
						item = U"flower_pot";

						x = 1920;
						int y_b = 767 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_b, hp, score, item, y));
					}
					else if (type == 3) {

						name = U"rumba_support";
						pattern = U"support";

						hp = 50;
						score = 0;
						item = U"banana";

						x = 1920;
						int y_a = 167 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));
					}
					//ステージ2ボス
					else if (type == 4) {

						name = U"rumba_support_2";
						pattern = U"support_2";

						hp = 150;
						score = 0;
						item = U"boots";

						x = 1920;
						int y_a = 167 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));
					}
					else if (type == 5) {

						name = U"rumba_support_2";
						pattern = U"support_2";

						hp = 150;
						score = 0;
						item = U"glass";

						x = 1920;
						int y_a = 767 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));
					}
					else if (type == 6) {

						name = U"rumba_support_2";
						pattern = U"support_3";

						hp = 150;
						score = 0;
						item = U"boots";

						x = 1920;
						int y_a = 167 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));
					}
					else if (type == 7) {

						name = U"rumba_support_2";
						pattern = U"support_3";

						hp = 150;
						score = 0;
						item = U"glass";

						x = 1920;
						int y_a = 767 + 100;

						will_emerge.push_back(Will_Emerge(name, pattern, x, y_a, hp, score, item, y));
					}
				}

				e.set_make_enemy_done();
			}

		}



		for (auto& w_e : will_emerge) {

			String name = w_e.name;
			String pattern = w_e.pattern;
			int x = w_e.x;
			int y = w_e.y;
			int hp = w_e.hp;
			int score = w_e.score;
			String item = w_e.item;
			double maker_y = w_e.maker_y;

			enemy.push_back(Enemy(name, pattern, x, y, hp, score, item, maker_y));
		}

	}

}
