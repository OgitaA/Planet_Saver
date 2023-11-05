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
		text = U"都市において発生する廃棄物のこと。経済の発展により、大量消費の生活様式が普及し、それに伴って廃棄物が量的・質的に増加したことが問題になっている。";
	}
	else if (display == 2) {
		title_text = U"海洋ゴミ";
		text = U"海洋に漂流、および海底に沈下、または海岸に漂流した廃棄物のこと。最も問題となっているのが分解されないプラスチックゴミで、海の生態系を破壊する恐れがある。";
	}
	else if (display == 3) {
		title_text = U"産業ゴミ";
		text = U"事業活動で生じる廃棄物のうち、定められた20の廃棄物のこと。これらの廃棄物は処分が不適切に行われると大気汚染や水質汚染を引き起こす可能性がある。";

	}
	else if (display == 0) {
		title_text = U"？？？";
		text = U"？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？";
	}

	FontAsset(U"UDP_G_B_40")(title_text).draw(1920 - 380 - 30 + 25 + 5, 180 + 20);

	draw_indention(FontAsset(U"UDP_G_R_25"), text, 1920 - 380 - 30 + 25 + 6, 180 + 20 + 55 - 3 + 5, 300);

	//FontAsset(U"UDP_G_R_25")(text).draw(1920 - 380 - 30 + 25, 180 + 20 + 55);
}
