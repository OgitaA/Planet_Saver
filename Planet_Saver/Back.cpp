#include"Back.hpp"

Back::Back() {


}

void Back::update(double _d_time) {

}

void Back::draw() {

	String name = U"back_" + Format(stage);

	TextureAsset(name).draw(0, 0);
}
