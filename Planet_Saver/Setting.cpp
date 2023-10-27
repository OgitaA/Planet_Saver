#include"Game.hpp"

void Game::change_bgm_volume() {

	double volume = double(bgm_volume) / double(10);

	for (size_t b = 0; b < bgm.size(); b++) {

		AudioAsset(bgm[b]).setVolume(volume);
	}
}

void Game::change_se_volume() {

	double volume = double(se_volume) / double(10);

	for (size_t s = 0; s < se.size(); s++) {

		AudioAsset(se[s]).setVolume(volume);
	}
}
