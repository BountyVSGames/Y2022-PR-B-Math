#include "vector3.h"

vector3::vector3(float x, float y, float z) : x(x), y(y), z(z) {};

//Returns reference to x, y or z depending on i
float& vector3::operator[](int i)
{
	return((&x))[i];
}
const float& vector3::operator[](int i) const
{
	return ((&x))[i];
}

vector3& vector3::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;

	return *this;
}
vector3& vector3::operator/=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;

	return *this;
}
vector3& vector3::operator+=(const vector3& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;

	return *this;
}
vector3& vector3::operator-=(const vector3& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;

	return *this;
}

inline vector3 vector3::operator*(float scalar)
{
	return vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}
inline vector3 vector3::operator/(float scalar)
{
	scalar = 1.f / scalar;
	return vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}
inline vector3 vector3::operator-(const vector3& vector)
{
	return vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}
inline vector3 vector3::operator+(const vector3& vector)
{
	return vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

inline float vector3::magnitude(const vector3& vector) {
	return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
}
inline vector3 vector3::normalize(vector3 vector)
{
	return (vector / magnitude(vector));
}

inline float vector3::dot(const vector3& vector)
{
	return (this->x * vector[0] + this->y * vector[1] + this->z * vector[2]);
}
vector3 vector3::cross(const vector3& vector)
{
	return (vector3(this->y * vector[2] - this->z * vector[1],
			this->z * vector[0] - this->x * vector[2],
			this->x * vector[1] - this->y * vector[0]));
}
