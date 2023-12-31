﻿#pragma once

# include <Siv3D.hpp> // Siv3D v0.6.12

class Enemy_Bullet {

public:

	Enemy_Bullet(String, double, double,int, double,double);

	void update(double);
	void draw();

	void set_up();

	Circle get_circle() { return circle; }
	int get_power() { return power; }

	void move();
	void move_normal();

private:

	double d_time;

	Circle circle;

	String name = U"";

	double speed;

	int power;

	double angle;

	String move_type = U"normal";

};
