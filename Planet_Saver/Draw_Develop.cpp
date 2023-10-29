#include"Game.hpp"

void Game::draw_develop() {

	FontAsset(U"UDP_G_B_40")(develop_image_name + U'|' + develop_editing_text).draw(100, 50);

	FontAsset(U"UDP_G_B_40")(U"item_" + develop_image_name).draw(100, 100, Palette::White);

	Rect back_rect(300, 300, 100, 100);
	back_rect.draw(Palette::White);

	TextureAsset(U"item_" + develop_image_name).draw(300, 300);



	for (auto& r : develop_select_rect) {

		Rect rect = r.rect;
		String name = r.name;

		rect.draw(Palette::White);

		if (name == develop_shape) {
			rect.draw(Palette::Yellow);
		}

		FontAsset(U"UDP_G_B_40")(name).draw(rect.x, rect.y, Palette::Black);
	}

	if (develop_shape == U"Rect") {

		int x = develop_rect_start.x;
		int y = develop_rect_start.y;
		int w = develop_rect_end.x - develop_rect_start.x;
		int h = develop_rect_end.y - develop_rect_start.y;


		Rect rect(develop_rect_start.x, develop_rect_start.y, w, h);
		rect.drawFrame(5, Palette::Red);

		FontAsset(U"UDP_G_B_40")(U"x::" + Format(x - 300)).draw(100, 800, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"y::" + Format(y - 300)).draw(100, 850, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"w::" + Format(w)).draw(100, 900, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"h::" + Format(h)).draw(100, 950, Palette::White);


	}
	else if (develop_shape == U"Quad") {

		Quad quad(develop_quad_1, develop_quad_2, develop_quad_3, develop_quad_4);
		quad.drawFrame(5, Palette::Red);

		int a_x = develop_quad_1.x - 300;
		int a_y = develop_quad_1.y - 300;
		int b_x = develop_quad_2.x - 300;
		int b_y = develop_quad_2.y - 300;
		int c_x = develop_quad_3.x - 300;
		int c_y = develop_quad_3.y - 300;
		int d_x = develop_quad_4.x - 300;
		int d_y = develop_quad_4.y - 300;

		Vec2 a{ a_x,a_y };
		Vec2 b{ b_x,b_y };
		Vec2 c{ c_x,c_y };
		Vec2 d{ d_x,d_y };

		FontAsset(U"UDP_G_B_40")(U"1::" + Format(a)).draw(100, 800, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"2::" + Format(b)).draw(100, 850, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"3::" + Format(c)).draw(100, 900, Palette::White);
		FontAsset(U"UDP_G_B_40")(U"4::" + Format(d)).draw(100, 950, Palette::White);

		FontAsset(U"UDP_G_B_40")(develop_quad_scene).draw(500, 875, Palette::White);
	}








}
