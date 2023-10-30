#include"Game.hpp"

void Game::update_develop() {

	Cursor::RequestStyle(CursorStyle::Arrow);

	Rect screen(0, 0, 1920, 1080);

	bool clicked = false;

	for (auto& r : develop_select_rect) {

		Rect rect = r.rect;
		String name = r.name;

		//クリックされた
		if (rect.leftClicked()) {
			develop_shape = name;

			clicked = true;
		}
	}

	for (auto& r : develop_kind_select_rect) {

		Rect rect = r.rect;
		String name = r.name;

		//クリックされた
		if (rect.leftClicked()) {
			develop_kind = name;

			clicked = true;
		}
	}



	// キーボードからテキストを入力
	TextInput::UpdateText(develop_image_name);

	// 未変換の文字入力を取得
	develop_editing_text = TextInput::GetEditingText();



	if (clicked == false) {

		if (develop_shape == U"Rect") {

			if (develop_rect_scene == 0) {

				if (screen.leftClicked()) {

					develop_rect_start = Cursor::Pos();

					if (develop_rect_start.x < 0) {
						develop_rect_start.x = 0;
					}
					if (develop_rect_start.y < 0) {
						develop_rect_start.y = 0;
					}

					develop_rect_scene = 1;
				}
			}
			else if (develop_rect_scene == 1) {

				develop_rect_end = Cursor::Pos();

				if (!screen.leftPressed()) {
					
					develop_rect_scene = 0;	
				}
			}

		}
		else if (develop_shape==U"Quad") {

			if (develop_quad_scene == 0) {

				if (screen.leftClicked()) {

					develop_quad_1 = Cursor::Pos();
					develop_quad_scene++;
				}
			}
			else if (develop_quad_scene == 1) {

				if (screen.leftClicked()) {

					develop_quad_2 = Cursor::Pos();
					develop_quad_scene++;
				}
			}
			else if (develop_quad_scene == 2) {

				if (screen.leftClicked()) {

					develop_quad_3 = Cursor::Pos();
					develop_quad_scene++;
				}
			}
			else if (develop_quad_scene == 3) {

				if (screen.leftClicked()) {

					develop_quad_4 = Cursor::Pos();
					develop_quad_scene = 0;
				}
			}
		}

	}

	if (screen.rightClicked()) {
		main_scene = 1;
	}

}
