#pragma once
#include "vector3.h"

class matrix
{
public:
	matrix() = default;
	matrix(float v00, float v01, float v02, 
			float v10, float v11, float v12, 
				float v20, float v21, float v22);
	matrix(float setValues[3][3]);
	matrix(const vector3& a, const vector3& b, const vector3& c);
	~matrix() = default;

	//Returns specific entry of the matrix
	float& operator()(int i, int j);
	const float& operator()(int i, int j) const;

	//Returns row as vector
	vector3& operator[](int j);
	const vector3& operator[](int j) const;

	matrix operator*(const matrix& matrix);
	vector3 operator*(const vector3& vector);
private:
	float n[3][3];
};