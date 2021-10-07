#pragma once 
#include <math.h>
#include "Math.h"
#include "Quaternion.h"

namespace Matrix {
	inline void Translate(float* matrix, float x, float y, float z) {

		matrix[12] = x;
		matrix[13] = y;
		matrix[14] = z;
		matrix[15] = 1.0f;

	}

	inline void Scale(float* matrix, float x, float y, float z) {
		matrix[0] = matrix[0] * x;
		matrix[1] = matrix[1] * x;
		matrix[2] = matrix[2] * x;
		matrix[4] = matrix[4] * y;
		matrix[5] = matrix[5] * y;
		matrix[6] = matrix[6] * y;
		matrix[8] = matrix[8] * z;
		matrix[9] = matrix[9] * z;
		matrix[10] = matrix[10] * z;
		matrix[15] = 1.0f;
	}

	inline void CreateFromQuaternion(float* matrix,const Quaternion& q) {
		matrix[0] = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
		matrix[1] = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
		matrix[2] = 2.0f * q.x * q.z - 2.0f * q.w * q.y;
		matrix[3] = 0.0f;

		matrix[4] = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
		matrix[5] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
		matrix[6] = 2.0f * q.y * q.z + 2.0f * q.w * q.x;
		matrix[7] = 0.0f;

		matrix[8] = 2.0f * q.x * q.z + 2.0f * q.w * q.y;
		matrix[9] = 2.0f * q.y * q.z - 2.0f * q.w * q.x;
		matrix[10] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;
		matrix[11] = 0.0f;

		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}

	inline float* ComputePosition(float* center, float* rotation, float* rayon) {
		float rotationX = Maths::toRadians(rotation[0]);
		float rotationY = Maths::toRadians(rotation[1]);
		float rotationZ = Maths::toRadians(rotation[2]);

		float rayonX = rayon[0];
		float rayonY = rayon[1];
		float rayonZ = rayon[2];

		float positionY = rayonY * Maths::cos(rotationX) - rayonZ * Maths::sin(rotationX);
		float positionZ = rayonZ * Maths::cos(rotationX) + rayonY * Maths::sin(rotationX);

		float positionX = rayonX * Maths::cos(rotationY) + positionZ * Maths::sin(rotationY);
		positionZ = positionZ * Maths::cos(rotationY) - rayonX * Maths::sin(rotationY);

		float tempX = positionX;
		float tempY = positionY;

		positionX = tempX * Maths::cos(rotationZ) - tempY * Maths::sin(rotationZ);
		positionY = tempY * Maths::cos(rotationZ) + tempX * Maths::sin(rotationZ);


		positionX += center[0];
		positionY += center[1];
		positionZ += center[2];

		float position[3] = { positionX, positionY, positionZ };
		return position;
	}

};