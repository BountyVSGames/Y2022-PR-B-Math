#pragma once
#include <cstdio>
#include <cmath>

class vector3
{
public:
	//vector3() = default;
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

	inline float magnitude();
	inline vector3 normalize(vector3 vector);

	inline float dot(const vector3& vector);
	inline const float dot(const vector3& a, const vector3& b) const;
	inline vector3 cross(const vector3& vector);
	inline const vector3 cross(const vector3& vector) const;

	inline vector3 project(const vector3& a, const vector3& b);
	inline vector3 reject(const vector3& a, const vector3& b);
private:
	float x, y, z;
};

static vector3 operator*(const vector3& vector, float scalar)
{
	return vector3(vector[0] * scalar, vector[1] * scalar, vector[2] * scalar);
}
static vector3 operator-(const vector3& a, const vector3& b)
{
	return vector3(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

static vector3 cross(const vector3& a, const vector3& b)
{
	return (vector3(a[1] * b[2] - a[2] * b[1],
		a[2] * b[0] - a[0] * b[2],
		a[0] * b[1] - a[2] * b[0]));
}

static float magnitude(const vector3& vector)
{
	return sqrtf((vector[0] * vector[0]) + (vector[1] * vector[1]) + (vector[2] * vector[2]));
}

static float dot(const vector3& a, const vector3& b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}