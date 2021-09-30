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

	float componentPositionX = m_position[0] * scale[0];
	float componentPositionY = m_position[1] * scale[1];
	float componentPositionZ = m_position[2] * scale[2];

	float componentScaleX = m_scale[0] * scale[0];
	float componentScaleY = m_scale[1] * scale[1];
	float componentScaleZ = m_scale[2] * scale[2];


	float componentRotationX = Maths::toRadians(m_rotation[0] + rotation[0]);
	float componentRotationY = Maths::toRadians(m_rotation[1] + rotation[1]);
	float componentRotationZ = Maths::toRadians(m_rotation[2] + rotation[2]);

	/// <Actor Rotation>

	float rotationX = Maths::toRadians(rotation[0]);
	float rotationY = Maths::toRadians(rotation[1]);
	float rotationZ = Maths::toRadians(rotation[2]);

	float positionY = componentPositionY * Maths::cos(rotationX) - componentPositionZ * Maths::sin(rotationX);
	float positionZ = componentPositionZ * Maths::cos(rotationX) + componentPositionY * Maths::sin(rotationX);

	float positionX = componentPositionX * Maths::cos(rotationY) + positionZ * Maths::sin(rotationY);
	positionZ = positionZ * Maths::cos(rotationY) - componentRotationX * Maths::sin(rotationY);

	float tempX = positionX;
	float tempY = positionY;

	positionX = tempX * Maths::cos(rotationZ) - tempY * Maths::sin(rotationZ);
	positionY = tempY * Maths::cos(rotationZ) + tempX * Maths::sin(rotationZ);

	positionX += position[0] * scale[0];
	positionY += position[1] * scale[1];
	positionZ += position[2] * scale[2];

	/*float* actorPosition = Matrix::ComputePosition(position, rotation, scale);*/

	/// <Actor Rotation>

	Quaternion rotationQ;

	rotationQ = Quaternion(axeX, componentRotationX);
	rotationQ = Quaternion::concatenate(rotationQ, Quaternion(axeY, componentRotationY));
	rotationQ = Quaternion::concatenate(rotationQ, Quaternion(axeZ, componentRotationZ));

	Matrix::CreateFromQuaternion(matrix, rotationQ);
	Matrix::Translate(matrix, positionX, positionY, positionZ);
	Matrix::Scale(matrix, componentScaleX, componentScaleY, componentScaleZ);


	bgfx::setTransform(matrix);

	bgfx::setVertexBuffer(0, m_vbh);
	bgfx::setIndexBuffer(m_ibh);

	bgfx::submit(0, m_program);
	

}


