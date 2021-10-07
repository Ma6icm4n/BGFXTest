#pragma once
#include "Actor.h"
#include "SimpleCube.h"
#include "Branch.h"
#include "Time.h"
#include "Quaternion.h"

class Roundabout : public Actor {
public:
	Roundabout();
	virtual ~Roundabout();
	Roundabout(const Roundabout&) = delete;
	Roundabout& operator=(const Roundabout&) = delete;

	void init() override;
	void update() override;

private:
	SimpleCube* base;
	Branch* branch1;
	Branch* branch2;
	Branch* branch3;
	Branch* branch4;
	Branch* hand1;
	Branch* hand2;
	Branch* hand3;
	Branch* hand4;
	Branch* cup1;
	Branch* cup2;
	Branch* cup3;
	Branch* cup4;
	Branch* cup5;
	Branch* cup6;
};