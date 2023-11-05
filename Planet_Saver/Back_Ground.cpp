#include"Back_Ground.hpp"

Back_Ground::Back_Ground() {


}

void Back_Ground::update(double _d_time) {

}

void Back_Ground::draw() {

	String name = U"back_" + Format(stage);

	TextureAsset(name).draw(0, 0);
}
