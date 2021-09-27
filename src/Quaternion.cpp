#include "Quaternion.h"

const Quaternion Quaternion::base(0.0f, 0.0f, 0.0f, 1.0f);

Quaternion::Quaternion(float xP, float yP, float zP, float wP) {
	set(xP, yP, zP, wP);
}

Quaternion::Quaternion(const float* ax, float ang) {
	float scalar = Maths::sin(ang / 2.0f);
	x = ax[0] * scalar;
	y = ax[1] * scalar;
	z = ax[2] * scalar;
	w = Maths::cos(ang / 2.0f);
}

void Quaternion::set(float xP, float yP, float zP, float wP) {
	x = xP;
	y = yP;
	z = zP;
	w = wP;
}

void Quaternion::conjugate() {
	x *= -1.0f;
	y *= -1.0f;
	z *= -1.0f;
}

void Quaternion::normalize() {
	float len = length();
	x /= len;
	y /= len;
	z /= len;
	w /= len;
}