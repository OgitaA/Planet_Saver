#pragma once

class Gauge_Effect {

public:

	Gauge_Effect(String _type,int _pos) {
		type = _type;
		pos = _pos;
	}

	void update(double _d_time) {

		count += _d_time;

		flash_count += _d_time;

		if (flash_count >= 0.1) {

			if (flash == true) {
				flash = false;
			}
			else if (flash == false) {
				flash = true;
			}

			flash_count = 0;
		}
	}

	bool get_delete() {

		if (count >= delete_count) {
			return true;
		}

		return false;

	}

	

	String get_type() { return type; }
	int get_pos() { return pos; }

	void draw() {

		const int edge_x = 30;

		const int moji_w = 120;

		const int interval = 350;

		const int gauge_w = 120;

		const int gauge_space = 40;

		int x = 0;


		//burn

		if (type == U"burn") {

			const int burn = edge_x;

			x = burn + gauge_w + gauge_space * (pos - 1);

		}
		else if (type == U"non_burn") {

			//non_burn

			const int non_burn = edge_x + interval;

			x = non_burn + gauge_w + gauge_space * (pos - 1);

		}
		else if (type == U"recycle") {

			//recycle

			const int recycle = edge_x + interval * 2;

			x = recycle + gauge_w + gauge_space * (pos - 1);

		}

		if (flash == true) {
			TextureAsset(U"gauge_effect").draw(x, 52);
		}
	}

private:

	String type = U"";

	int pos = 0;

	double count = 0;

	double delete_count = 1.5;

	bool flash = true;

	double flash_count = 0;

};
