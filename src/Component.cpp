#include "Component.h"

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

void Component::destroy() {
	if (isInit) {
		bgfx::destroy(m_vbh);
		bgfx::destroy(m_ibh);
		bgfx::destroy(m_program);
	}
}

void Component::update() {

	float axeX[3] = { 1, 0, 0 };
	float axeY[3] = { 0, 1, 0 };
	float axeZ[3] = { 0, 0, 1 };

	float* position = owner.getPosition();
	float* scale = owner.getScale();
	float* rotation = owner.getRotation();

	float positionX = m_position[0] + position[0];
	float positionY = m_position[1] + position[1];
	float positionZ = m_position[2] + position[2];

	float scaleX = m_scale[0] * scale[0];
	float scaleY = m_scale[1] * scale[1];
	float scaleZ = m_scale[2] * scale[2];


	float rotationX = Maths::toRadians(m_rotation[0] + rotation[0]);
	float rotationY = Maths::toRadians(m_rotation[1] + rotation[1]);
	float rotationZ = Maths::toRadians(m_rotation[2] + rotation[2]);

	Quaternion rotationQ;

	rotationQ = Quaternion(axeX, rotationX);
	rotationQ = Quaternion::concatenate(rotationQ, Quaternion(axeY, rotationY));
	rotationQ = Quaternion::concatenate(rotationQ, Quaternion(axeZ, rotationZ));

	Matrix::CreateFromQuaternion(matrix, rotationQ);
	Matrix::Translate(matrix, positionX, positionY, positionZ);
	Matrix::Scale(matrix, scaleX, scaleY, scaleZ);


	bgfx::setTransform(matrix);

	bgfx::setVertexBuffer(0, m_vbh);
	bgfx::setIndexBuffer(m_ibh);

	bgfx::submit(0, m_program);
	

}


