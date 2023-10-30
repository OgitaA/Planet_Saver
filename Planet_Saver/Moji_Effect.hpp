#pragma once

class Moji_Effect {

public:

	Moji_Effect(String,int,int,String);

	void update(double);

	void draw();

	bool get_delete() {

		if (count >= delete_count) {
			return true;
		}
		else {
			return false;
		}
	}

private:

	int x = 0;
	int y = 0;

	String text;

	String color_type;

	double count = 0;

	double delete_count = 2;

};
