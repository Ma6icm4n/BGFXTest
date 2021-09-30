#include "Roundabout.h"



Roundabout::Roundabout() : base(nullptr), branch1(nullptr), branch2(nullptr), branch3(nullptr),
hand1(nullptr), hand2(nullptr), hand3(nullptr), cup1(nullptr), cup2(nullptr), cup3(nullptr), 
	cup4(nullptr), cup5(nullptr), cup6(nullptr) {

}

Roundabout::~Roundabout() {}

void Roundabout::init() {
	base = new SimpleCube(this);
	base->setPosition(0.0f, 0.0f, 0.0f);
	

	branch1 = new Branch(this);
	branch1->setPosition(5.0f, 0.0f, 0.0f);
	branch1->setScale(5.0f, 0.02f, 1.0f);
	

	Actor::init();
}

void Roundabout::update() {
	float time = Time::getTime();
	
	

	float rayon[3] = { 2.0f, 0.0f, 2.0f };
	float rayonNeg[3] = { -1.0f, 0.0f, -1.0f };
	float rayonBase[3];
	rayonBase[0]= base->getPosition()[0] - 1.5;
	rayonBase[1] = base->getPosition()[1] - 0.5;
	rayonBase[2]= base->getPosition()[2] - 1.5;
	


	/*float* branch1Position = Matrix::ComputePosition(rayonBase, base->getRotation(), rayon);
	branch1->setPosition(branch1Position[0], branch1Position[1], branch1Position[2]);*/
	//branch1->setRotation(0.0f, base->getRotation()[1] + 125, Maths::cos(time) * 45);
	

	Actor::update();
}