#include"Game.hpp"

void Game::draw_stageclear() {

	TextureAsset(U"black").draw(0, 0, ColorF(1.0, 0.7));
	TextureAsset(U"stage_clear_doctor").draw(1920 - 380 - 30 - 100, 1080 - 700 - 70);


	FontAsset(U"KIKA_R_120")(U"STAGE CLEAR").drawAt(1920 / 2, 200, Palette::White);

	FontAsset(U"UD_M_B_50")(U"★スコア　" + Format(score)+U"★").drawAt(1920 / 2, 400-30, Palette::White);

	FontAsset(U"UD_M_B_50")(U"～集めたごみ～").drawAt(1920 / 2, 450+50, Palette::White);

	int burn_count = player.get_burn_count();
	int non_burn_count = player.get_non_burn_count();
	int recycle_count = player.get_recycle_count();

	FontAsset(U"UD_M_B_50")(U"燃えるごみ　" + Format(burn_count) + U"コ").drawAt(1920 / 2, 550+50, Palette::Red);
	FontAsset(U"UD_M_B_50")(U"燃えないごみ　" + Format(non_burn_count) + U"コ").drawAt(1920 / 2, 600+20+50, Palette::Blue);
	FontAsset(U"UD_M_B_50")(U"資源ごみ　" + Format(recycle_count) + U"コ").drawAt(1920 / 2, 650 + 40 + 50, Color(50, 151, 0));

	FontAsset(U"UD_M_B_50")(U"Zキーを押してステージセレクトへ").drawAt(1920 / 2, 900, Palette::White);




	
}
