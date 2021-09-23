#include "Actor.h"
#include <algorithm>
#include "Game.h"
#include "Component.h"

Actor::Actor() :
	state(Actor::ActorState::active),
	mustRecomputeWorldTransform(true),
	game(Game::instance()) {

	game.addActor(this);
}

Actor::~Actor() {
	game.removeActor(this);

	while (!components.empty()) {
		delete components.back();
	}
}

void Actor::setPosition() {}

void Actor::setScale() {}

void Actor::setRotation() {}

void Actor::setState() {}

void Actor::computeWorldTransform() {}

void Actor::update(float dt) {

	if (state == Actor::ActorState::active) {
		computeWorldTransform();
		UpdateComponents(dt);
		updateActor(dt);
		computeWorldTransform();
	}
}

void Actor::UpdateComponents(float dt) {

	for (auto component : components) {
		component->update(dt);
	}
}

void Actor::updateActor(float dt) {}

void Actor::addComponent(Component* component) {
	int order = component->getUpdateOrder();
	auto iter = begin(components);
	for (; iter != end(components); ++iter) {
		if (order < (*iter)->getUpdateOrder()) {
			break;
		}
	}

	components.insert(iter, component);
}

void Actor::removeComponent(Component* component) {
	
	auto iter = std::find(begin(components), end(components), component);
	if (iter != end(components)) {
		components.erase(iter);
	}
}

