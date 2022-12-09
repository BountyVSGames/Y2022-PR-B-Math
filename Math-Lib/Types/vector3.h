#pragma once
#include <stdio.h>
#include <math.h>

class vector3
{
public:
	vector3() = default;
	vector3(float x, float y, float z);
	~vector3() = default;

	float& operator[](int i);
	const float& operator[](int i) const;

	vector3& operator*=(float scalar);
	vector3& operator/=(float scalar);
	vector3& operator+=(const vector3& vector);
	vector3& operator-=(const vector3& vector);

	inline vector3 operator*(float scalar);
	inline vector3 operator/(float scalar);
	inline vector3 operator-(const vector3& vector);
	inline vector3 operator+(const vector3& vector);

	inline float magnitude(const vector3& vector);
	inline vector3 normalize(vector3 vector);

	inline float dot(const vector3& vector);
	inline vector3 cross(const vector3& vector);
private:
	float x, y, z;
};