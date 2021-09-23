#include "Actor.h"
#include <algorithm>
#include "Game.h"
#include "Component.h"

Actor::Actor() :
	state(Actor::ActorState::active),
	game(Game::instance()) 
{
	game.addActor(this);
}

Actor::~Actor() {
	destroy();
}

void Actor::setPosition(float x, float y, float z) {
	m_position[0] = x;
	m_position[1] = y;
	m_position[2] = z;
}

void Actor::setRotation(float x, float y, float z) {
	m_rotation[0] = x; 
	m_rotation[1] = y;
	m_rotation[2] = z;
}

void Actor::setScale(float x, float y, float z) {
	m_scale[0] = x;
	m_scale[1] = y;
	m_scale[2] = z;
}

void Actor::addComponents(Component* component) {
	int order = component->getUpdateOrder();
	auto iter = begin(components);
	for (; iter != end(components); ++iter) {
		if (order < (*iter)->getUpdateOrder()) {
			break;
		}
	}

	components.insert(iter, component);
	
}

void Actor::removeComponents(Component* component) {
	auto iter = std::find(begin(components), end(components), component);
	if(iter != end(components)) {
		components.erase(iter);
	}
}

void Actor::init() {
	for (auto component : components) {
		component->init();
	}
}

void Actor::update() {
	for (auto component : components) {
		component->update();
	}
}

void Actor::destroy() {
	components.clear();
}



