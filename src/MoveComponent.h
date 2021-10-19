#pragma once
#include "Component.h"
#include "Utils.h"

class MoveComponent : public Component {
public:
	MoveComponent(Actor* ownerP, int updataOrder = 10);
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator=(const MoveComponent&) = delete;

	float getForwardSpeed() const { return forwardSpeed; }
	float getAngularSpeed() const { return angularSpeed; }
	//float* getForwardVector();

	void setForwardSpeed(float forwardSpeedP);
	void setAngularSpeed(float angularSpeedP);

	/*void init() override;
	void update() override;

	void updateObjectRotation(float* rotationVelocity, float dt, float angularSpeed);*/

private:
	float forwardSpeed;
	float angularSpeed;
	float forwardVector[3] = { 0.0, 0.0, 0.0 };

};