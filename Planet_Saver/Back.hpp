#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Back {

public:

	Back();

	void update(double);
	void draw();

	void set_stage(int v) { stage = v; }

private:

	int stage = 1;
};
