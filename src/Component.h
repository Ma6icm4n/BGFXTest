#pragma once
#include "Utils.h"
#include "Actor.h"

class Actor;

class Component {
public:
	Component(Actor* ownerP, int updateOrderP = 100);
	Component() = delete;
	virtual ~Component();
	Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;

	void virtual init() { isInit = true; }
	void virtual update();
	void virtual destroy();

	void setPosition(float x, float y, float z);
	void setScale(float x, float y, float z);
	void setRotation(float x, float y, float z);

	int getUpdateOrder() const { return updateOrder; }
	float* getPosition() { return m_position; }
	float* getScale() { return m_scale; }
	float* getRotation() { return m_rotation; }


private:
	float m_position[3] = { 0, 0, 0 };
	float m_scale[3] = { 1, 1, 1 };
	float m_rotation[3] = { 0, 0, 0 };

protected:
	Actor& owner;
	int updateOrder;

	bgfx::VertexBufferHandle	m_vbh;
	bgfx::IndexBufferHandle		m_ibh;
	bgfx::ProgramHandle			m_program;

	float matrix[16];

	bool isInit;

};