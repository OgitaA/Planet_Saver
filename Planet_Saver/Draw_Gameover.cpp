#include"Game.hpp"

void Game::draw_gameover() {

	TextureAsset(U"black").draw(0, 0, ColorF(1.0, 0.7));

	TextureAsset(U"game_over_doctor").draw(1920 - 380 - 30 - 100, 1080 - 700 - 70);

	FontAsset(U"KIKA_R_120")(U"GAME OVER").drawAt(1920 / 2, 200,Palette::White);

	FontAsset(U"UD_M_B_50")(U"リトライしますか？").drawAt(1920 / 2, 550, Palette::White);

	double yes_alpha = 1;
	double no_alpha = 1;

	if (gameover_cur == 0) {
		no_alpha = 0.3;
	}
	else if (gameover_cur == 1) {
		yes_alpha = 0.3;
	}


	FontAsset(U"UD_M_B_40")(U"はい").drawAt(1920 / 2, 650+30, ColorF(1, 1,1, yes_alpha));

	FontAsset(U"UD_M_B_40")(U"いいえ").drawAt(1920 / 2, 750+30, ColorF(1, 1, 1, no_alpha));
}
