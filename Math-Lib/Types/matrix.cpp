#include "matrix.h"

matrix::matrix(float v00, float v01, float v02, 
				float v10, float v11, float v12, 
					float v20, float v21, float v22)
{
	n[0][0] = v00;
	n[0][1] = v01;
	n[0][2] = v02;
	n[1][0] = v10;
	n[1][1] = v11;
	n[1][2] = v12;
	n[2][0] = v20;
	n[2][1] = v21;
	n[2][2] = v22;
}
matrix::matrix(float setValues[3][3])
{
	n[0][0] = setValues[0][0];
	n[0][1] = setValues[0][1];
	n[0][2] = setValues[0][2];
	n[1][0] = setValues[0][0];
	n[1][1] = setValues[0][1];
	n[1][2] = setValues[0][2];
	n[2][0] = setValues[0][0];
	n[2][1] = setValues[0][1];
	n[2][2] = setValues[0][2];
}
matrix::matrix(const vector3& a, const vector3& b, const vector3& c)
{
	n[0][0] = a[0];
	n[0][1] = a[1];
	n[0][2] = a[2];

	n[1][0] = b[0];
	n[1][1] = b[1];
	n[1][2] = b[2];

	n[2][0] = c[0];
	n[2][1] = c[1];
	n[2][2] = c[2];
}

float& matrix::operator()(int i, int j)
{
	return n[j][i];
}
const float& matrix::operator()(int i, int j) const
{
	return n[j][i];
}

vector3& matrix::operator[](int j)
{
	return (*reinterpret_cast<vector3*>(n[j]));
}
const vector3& matrix::operator[](int j) const
{
	return (*reinterpret_cast<const vector3*>(n[j]));
}

matrix matrix::operator*(const matrix& m)
{
	return(matrix(operator()(0, 0) * m(0, 0), operator()(0, 1) * m(0, 1), operator()(0, 2) * m(0, 2),
		operator()(1, 0) * m(1, 0), operator()(1, 1) * m(1, 1), operator()(1, 2) * m(1, 2),
		operator()(2, 0) * m(2, 0), operator()(2, 1) * m(2, 1), operator()(2, 2) * m(2, 2)));
}
vector3 matrix::operator*(const vector3& vector)
{
	return(vector3(operator()(0, 0) * vector[0] + operator()(0, 1) * vector[1] + operator()(0, 2) * vector[2],
		operator()(1, 0) * vector[0] + operator()(1, 1) * vector[1] + operator()(1, 2) * vector[2],
		operator()(2, 0) * vector[0] + operator()(2, 1) * vector[1] + operator()(2, 2) * vector[2]));
}