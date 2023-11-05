#include"Game.hpp"

void Game::draw_indention(Font _font, String _text, int _x, int _y, int _wide) {

	//座標
	Vec2 basePos = { _x,_y };
	Vec2 penPos = basePos;

	int count_w = 0;


	// 文字単位で描画を制御するためのループ
	for (const auto& glyph : _font.getGlyphs(_text))
	{




		glyph.texture.draw(penPos + glyph.getOffset(), Palette::White);

		// ペンの X 座標を文字の幅の分進める
		penPos.x += glyph.xAdvance;

		//横幅カウント増加
		count_w += glyph.xAdvance;

		// 改行する
		if (count_w >= _wide)
		{
			// ペンの X 座標をリセット
			penPos.x = basePos.x;

			// ペンの Y 座標をフォントの高さ分進める
			penPos.y += _font.height() + 10;

			//カウントリセット
			count_w = 0;

			continue;
		}



	}
}
