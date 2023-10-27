#include"Game.hpp"

void Game::draw_stage_select() {

	TextureAsset(U"stage_select_back").draw(0, 0);

	FontAsset(U"UDP_G_B_100")(U"STAGE SELECT").drawAt(1920 / 2, 45 * 2, Palette::White);

	TextureAsset(U"stage_select_doctor").draw(1920 - 380 - 30, 1080 - 550 - 30);

	//Tips
	TextureAsset(U"stage_select_tips").draw(1920 - 380 - 30, 180);

	int b_w = 1000;
	int b_h = 250;

	int pos_x = (1920 - b_w) / 2;
	int pos_y = 200;

	int blank = 50;



	int select_x = pos_x;
	int select_y = pos_y + (b_h + blank) * (stage_select_cur);

	TextureAsset(U"stage_select_cur").draw(select_x - 50, select_y - 175);



	for (auto& b : stage_select_box) {

		int x = b.get_x();
		int y = b.get_y();

		int number = b.get_number();
		String name = b.get_name();

		int box_x = pos_x;
		int box_y = pos_y + (b_h + blank) * (number - 1);


		String box_name = U"stage_select_box_" + Format(number);

		TextureAsset(box_name).draw(box_x, box_y);

		FontAsset(U"UDP_G_B_40")(U"Stage " + Format(number)).draw(box_x + 30, box_y + 25);

		//ステージ解放済み
		if (clear_stage + 1 >= number) {

			FontAsset(U"UDP_G_B_70")(name).drawAt(box_x + b_w / 2, box_y + b_h / 2, Palette::White);

		}
		//ステージ解放されていない
		else {

			FontAsset(U"UDP_G_B_70")(U"???").drawAt(box_x + b_w / 2, box_y + b_h / 2, Palette::White);

		}

	}


	String title_text = U"";
	String text = U"";


	//表示するステージ番号

	int display = 0;
	display = stage_select_cur + 1;

	//ステージが解放されているか

	if (clear_stage + 1 >= display) {

	}
	else {
		display = 0;
	}



	if (display == 1) {
		title_text = U"都市ゴミ";
		text = U"都市において発生する廃棄物のこと。かつて都市部は経済活動が活発であり、大量消費の生活様式が普及していた。それに伴い廃棄物が量的・質的に増加したことで、都市部の持つ処理能力を遥かに超え都市機能は停止することとなった。";
	}
	else if (display == 2) {
		title_text = U"海洋ゴミ";
		text = U"海洋に漂流および海底に沈下、海岸に漂流した廃棄物のこと。街から発生したプラスチックが主で、2050年頃には魚類の総重量を超え、2060年頃には多くの海洋ゴミによって世界各地で漁業活動が不可能となり、食糧問題を引き起こすこととなった。";
	}
	else if (display == 3) {
		title_text = U"宇宙ゴミ";
		text = U"地球の衛星軌道を周回する人工物のこと。停止した人工衛星などによって宇宙ゴミは発生し、激化した宇宙開発競争によって、その数は爆発的に増加した。結果として無数の宇宙ゴミは多くの人工衛星を破壊し、文明の衰退を引き起こすこととなった。";
	}

	FontAsset(U"UDP_G_B_40")(title_text).draw(1920 - 380 - 30 + 25 + 5, 180 + 20);

	draw_indention(FontAsset(U"UDP_G_R_25"), text, 1920 - 380 - 30 + 25 + 6, 180 + 20 + 55 - 3, 300);

	//FontAsset(U"UDP_G_R_25")(text).draw(1920 - 380 - 30 + 25, 180 + 20 + 55);
}
