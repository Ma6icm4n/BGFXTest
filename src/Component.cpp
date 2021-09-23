#include "Component.h"
#include "Actor.h"

Component::Component(Actor* ownerP, int updateOrderP) : owner(*ownerP), updateOrder(updateOrderP) {
	owner.addComponents(this);
}

Component::~Component() {	
}

void Component::setPosition(float x, float y, float z) {
	m_position[0] = x;
	m_position[1] = y;
	m_position[2] = z;
}

void Component::setScale(float x, float y, float z) {
	m_scale[0] = x;
	m_scale[1] = y;
	m_scale[2] = z;
}

void Component::setRotation(float x, float y, float z) {
	m_rotation[0] = x;
	m_rotation[1] = y;
	m_rotation[2] = z;
}

void Component::update() {

}

void Component::destroy() {
	if (isInit) {
		bgfx::destroy(m_vbh);
		bgfx::destroy(m_ibh);
		bgfx::destroy(m_program);
	}
}
