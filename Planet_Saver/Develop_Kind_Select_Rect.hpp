#pragma once

class Develop_Kind_Select_Rect {

public:

	Develop_Kind_Select_Rect(int _x, int _y, int _w, int _h, String _name) {
		rect = Rect(_x, _y, _w, _h);
		name = _name;


	}

	Rect rect;
	String name;




};
