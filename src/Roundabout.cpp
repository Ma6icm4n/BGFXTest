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

	branch2 = new Branch(this);
	branch2->setPosition(-5.0f, 0.0f, 0.0f);
	branch2->setScale(5.0f, 0.02f, 1.0f);
	
	branch3 = new Branch(this);
	branch3->setPosition(0.0f, 0.0f, 5.0f);
	branch3->setScale(5.0f, 0.02f, 1.0f);
	branch3->setRotation(0.0f, 90.0f, 0.0f);

	branch4 = new Branch(this);
	branch4->setPosition(0.0f, 0.0f, -5.0f);
	branch4->setScale(5.0f, 0.02f, 1.0f);
	branch4->setRotation(0.0f, 90.0f, 0.0f);

	hand1 = new Branch(this);
	hand1->setPosition(10.0f, 0.0f, 0.0f);
	hand1->setScale(5.0f, 0.05f, .7f);
	hand1->setRotation(0.0f, 90.0f, 0.0f);
	
	hand2 = new Branch(this);
	hand2->setPosition(-10.0f, 0.0f, 0.0f);
	hand2->setScale(5.0f, 0.05f, .7f);
	hand2->setRotation(0.0f, 90.0f, 0.0f);
	
	hand3 = new Branch(this);
	hand3->setPosition(0.0f, 0.0f, 10.0f);
	hand3->setScale(5.0f, 0.05f, .7f);
	hand3->setRotation(0.0f, 0.0f, 0.0f);
	
	hand4 = new Branch(this);
	hand4->setPosition(0.0f, 0.0f, -10.0f);
	hand4->setScale(5.0f, 0.05f, .7f);
	hand4->setRotation(0.0f, 0.0f, 0.0f);

	cup1 = new Branch(this);
	cup1->setPosition(10.0f, 1.0f, 5.0f);
	cup1->setScale(0.7f, 0.7f, 0.7);
	
	cup2 = new Branch(this);
	cup2->setPosition(10.0f, 1.0f, -5.0f);
	cup2->setScale(0.7f, 0.7f, 0.7);

	Actor::init();
}

void Roundabout::update() {

	float rayon[3] = { 5.0f, 0.0f, 0.0f };
	float noyar[3] = { -5.0f, 0.0f, 0.0f };
	float time = Time::getTime();

	hand1->setRotation(0.0f, time * 65, 0.0f);
	hand2->setRotation(0.0f, time * 88, 0.0f);
	hand3->setRotation(0.0f, time * 79, 0.0f);
	hand4->setRotation(0.0f, time * 150, 0.0f);

	float* hand1Position = hand1->getPosition();
	float* hand1Rotation = hand1->getRotation();

	float* computedCup1Position = Matrix::ComputePosition(hand1Position, hand1Rotation, rayon);
	cup1->setRotation(0.0f, -time * 45 *2, 0.0f);
	cup1->setPosition(computedCup1Position[0], cup1->getPosition()[1], computedCup1Position[2]);

	float* computedCup2Position = Matrix::ComputePosition(hand1Position, hand1Rotation, noyar);
	cup2->setRotation(0.0f, -time * 45 * 2, 0.0f);
	cup2->setPosition(computedCup2Position[0], cup2->getPosition()[1], computedCup2Position[2]);
	
	
	

	Actor::update();
}