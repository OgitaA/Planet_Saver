#include"Game.hpp"

//SE予約
void Game::play_se(int v) {

	se_will << v;

}

//更新
void Game::update_se_main(double d_time) {

	for (size_t s = 0; s < se_lock.size(); s++) {
		if (se_lock[s] > 0) {
			se_lock[s] -= d_time;
		}
	}

}

//鳴らす
void Game::play_se_main() {

	double volume = double(se_volume) / double(10);

	for (size_t s = 0; s < se_will.size(); s++) {

		int kind = se_will[s];

		if (se_lock[kind] <= 0) {
			AudioAsset(se[kind]).playOneShot(volume);
			se_lock[kind] = 0.1;
		}
	}

	se_will.clear();
}






//BGMスタート
void Game::play_bgm(int v) {
	AudioAsset(bgm[v]).play();
}


//BGM止める
void Game::stop_bgm() {

	for (size_t i = 0; i < bgm.size(); i++) {
		AudioAsset(bgm[i]).stop();
	}
}




