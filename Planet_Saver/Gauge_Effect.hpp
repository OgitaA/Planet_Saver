#pragma once

class Gauge_Effect {

public:

	Gauge_Effect() {

	}

	void update(double _d_time) {
		count += _d_time;
	}

	bool get_delete() {

		if (count >= delete_count) {
			return true;
		}

		return false;

	}


private:

	double count = 0;

	double delete_count = 2;

};
