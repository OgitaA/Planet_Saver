#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Catcher {

public:

	Catcher() {

		rect = Rect(0, 0, 118, 41);

		hit_rect = rect;
	}

	void first(double, double);

	void update(double, double, double, String);

	void draw();

	void reset();

	RectF get_hit_rect() { return hit_rect; }

	bool get_operation() {return  operation; }

	void plus_item(String _name,String _type) { item.push_back(Item(_name,_type)); }

	bool check_full_item(){

		if (item.size() >= item_max) {
			return true;
		}
		else {
			return false;
		}
	}

	size_t get_item_size() { return item.size(); }
	String get_status() { return status; }
	int get_move_y() { return move_y; }
	void get_item_name(){}
	String get_item_type(int index) {return item[index].type; }

	void clear_item() { item.clear(); }

	void set_error(bool v) { error = v; }

	//ミスの処理
	void set_miss(bool v) { miss = v; }

	

private:

	RectF rect;

	double adjust_x = 0;
	const double adjust_y = 28;

	double move_y = 0;

	bool operation = false;

	String status = U"down";

	double speed = 400;

	double count = 0;

	RectF hit_rect;

	String mode = U"burn";

	//キャッチしたアイテム

	class Item {
	public:
		String name;
		String type;
	};

	Array<Item> item;

	int item_max = 3;

	bool error = false;

	//プレイヤーのミスをうける
	bool miss = false;
	
};
