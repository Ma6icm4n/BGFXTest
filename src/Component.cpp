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

	float* actorPosition = owner.getPosition();
	float* actorScale = owner.getScale();
	float* actorRotation = owner.getRotation();

	float componentRotationX = Maths::toRadians(m_rotation[0] + actorRotation[0]);
	float componentRotationY = Maths::toRadians(m_rotation[1] + actorRotation[1]);
	float componentRotationZ = Maths::toRadians(m_rotation[2] + actorRotation[2]);

	float scaledPositionComponentX = m_position[0] * actorScale[0];
	float scaledPositionComponentY = m_position[1] * actorScale[1];
	float scaledPositionComponentZ = m_position[2] * actorScale[2];

	float componentScaleX = m_scale[0] * actorScale[0];
	float componentScaleY = m_scale[1] * actorScale[1];
	float componentScaleZ = m_scale[2] * actorScale[2];

	/// <Actor Rotation>

	float actorRotationX = Maths::toRadians(actorRotation[0]);
	float actorRotationY = Maths::toRadians(actorRotation[1]);
	float actorRotationZ = Maths::toRadians(actorRotation[2]);

	float positionY = scaledPositionComponentY * Maths::cos(actorRotationX) - scaledPositionComponentZ * Maths::sin(actorRotationX);
	float positionZ = scaledPositionComponentZ * Maths::cos(actorRotationX) + scaledPositionComponentY * Maths::sin(actorRotationX);

	float positionX = scaledPositionComponentX * Maths::cos(actorRotationY) + positionZ * Maths::sin(actorRotationY);
	positionZ = positionZ * Maths::cos(actorRotationY) - scaledPositionComponentX * Maths::sin(actorRotationY);

	float tempX = positionX;
	float tempY = positionY;

	positionX = tempX * Maths::cos(actorRotationZ) - tempY * Maths::sin(actorRotationZ);
	positionY = tempY * Maths::cos(actorRotationZ) + tempX * Maths::sin(actorRotationZ);
	
	positionX += actorPosition[0] * actorScale[0];
	positionY += actorPosition[1] * actorScale[1];
	positionZ += actorPosition[2] * actorScale[2];

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


