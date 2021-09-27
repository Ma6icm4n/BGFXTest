#pragma once
#include "Math.h"

class Quaternion
{
public:
	
	Quaternion() {
		*this = Quaternion::base;
	}

	explicit Quaternion(float radX, float radY, float radZ, float radW);

	explicit Quaternion(const float* ax, float ang);

	void set(float radX, float radY, float radZ, float radW);
	void conjugate();
	void normalize();

	float lengthSq() const {
		return (x * x + y * y + z * z + w * w);
	}

	float length() const {
		return Maths::sqrt(lengthSq());
	}

	static Quaternion normalize(const Quaternion& q) {
		Quaternion retVal = q;
		retVal.normalize();
		return retVal;
	}

	static Quaternion lerp(const Quaternion& a, const Quaternion& b, float f) {
		Quaternion retVal;
		retVal.x = Maths::lerp(a.x, b.x, f);
		retVal.y = Maths::lerp(a.y, b.y, f);
		retVal.z = Maths::lerp(a.z, b.z, f);
		retVal.w = Maths::lerp(a.w, b.w, f);

		retVal.normalize();
		return retVal;
	}

	static float dot(const Quaternion& a, const Quaternion& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	static Quaternion slerp(const Quaternion& a, const Quaternion& b, float f) {
		float rawCosm = Quaternion::dot(a, b);
		float cosom = -rawCosm;
		if (rawCosm >= 0.0f) {
			cosom = rawCosm;
		}

		float scale0, scale1;

		if (cosom < 0.9999f) {
			const float omega = Maths::acos(cosom);
			const float invSin = 1.0f / Maths::sin(omega);
			scale0 = Maths::sin((1.0f - f) * omega) * invSin;
			scale1 = Maths::sin(f * omega) * invSin;
		}
		else {
			scale0 = 1.0f - f;
			scale1 = f;
		}
		if (rawCosm < 0.0f) {
			scale1 = -scale1;
		}

		Quaternion retVal;
		retVal.x = scale0 * a.x + scale1 * b.x;
		retVal.y = scale0 * a.y + scale1 * b.y;
		retVal.z = scale0 * a.z + scale1 * b.z;
		retVal.w = scale0 * a.w + scale1 * b.w;
		retVal.normalize();
		return retVal;
	}

	static Quaternion concatenate(const Quaternion& a, Quaternion& b) {
		Quaternion retVal;

		float newVec[4] = { b.w * a.x + a.w * b.x + a.y * b.z - a.z * b.y,
							b.w * a.y + a.w * b.y + a.z * b.x - a.x * b.z,
							b.w * a.z + a.w * a.z + a.x * b.y - a.y * b.x,
							a.w * b.w - (a.x * b.x + a.y * b.y + a.z * b.z) };
		retVal.x = newVec[0];
		retVal.y = newVec[1];
		retVal.z = newVec[2];
		retVal.w = newVec[3];

		return retVal;
	}

	static const Quaternion base;

	float x;
	float y;
	float z;
	float w;
	
};