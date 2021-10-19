#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"
#include "Window.h"

MoveComponent::MoveComponent(Actor* ownerP, int updateOrderP) : Component(ownerP, updateOrderP), forwardSpeed(0.0f), angularSpeed(0.0f) {


}

void MoveComponent::setForwardSpeed(float forwardSpeedP) {
	forwardSpeed = forwardSpeedP;
}

void MoveComponent::setAngularSpeed(float angularSpeedP) {
	angularSpeed = angularSpeedP;
}

//float* getForwardVector() {
//	owner.rotation
//}