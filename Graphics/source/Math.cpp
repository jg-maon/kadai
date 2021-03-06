#include "Math.h"

#include <cmath>

#pragma region VECTOR2
VECTOR2::VECTOR2()
	: x(0.f)
	, y(0.f)
{
}
VECTOR2::VECTOR2(float x, float y)
	: x(x)
	, y(y)
{
}

VECTOR2::VECTOR2(const VECTOR3& v)
	: x(v.x)
	, y(v.y)
{
}

VECTOR2::VECTOR2(const VECTOR4& v)
	: x(v.x)
	, y(v.y)
{
}


VECTOR2::~VECTOR2()
{
}

VECTOR2& VECTOR2::operator = (const VECTOR2& v)
{
	if (this != &v)
	{
		this->x = v.x;
		this->y = v.y;
	}

	return *this;
}


VECTOR2 VECTOR2::operator-()const
{
	return VECTOR2(-x, -y);
}

VECTOR2& VECTOR2::negate()
{
	x = -x;
	y = -y;
	return *this;
}

float VECTOR2::length() const
{
	return std::sqrtf(x*x + y*y);
}

VECTOR2& VECTOR2::normalize()
{
	float mag = 1.f / length();
	x *= mag;
	y *= mag;
	return *this;
}

float VECTOR2::dot(const VECTOR2& v) const
{
	return x*v.x + y*v.y;
}

float VECTOR2::cross(const VECTOR2& v) const
{
	return x*v.y - y*v.x;
}

#pragma endregion // VECTOR2

#pragma region VECTOR3



VECTOR3::VECTOR3()
{
	x = y = z = 0.f;
}

VECTOR3::VECTOR3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

VECTOR3::VECTOR3(const VECTOR2& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = 0.f;
}
VECTOR3::VECTOR3(const DxLib::VECTOR& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}
VECTOR3::VECTOR3(const VECTOR4& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

VECTOR3::~VECTOR3()
{
}

VECTOR3& VECTOR3::operator = (DxLib::VECTOR& v)
{
	if (this != &v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	return *this;
}


VECTOR3 VECTOR3::operator-()const
{
	return VECTOR3(-x, -y, -z);
}

VECTOR3& VECTOR3::negate()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

float VECTOR3::length() const
{
	return std::sqrtf(x*x + y*y + z*z);
}

VECTOR3& VECTOR3::normalize()
{
	float mag = 1.f / length();
	x *= mag;
	y *= mag;
	z *= mag;
	return *this;
}

float VECTOR3::dot(const VECTOR3& v) const
{
	return x*v.x + y*v.y + z*v.z;
}

VECTOR3 VECTOR3::cross(const VECTOR3& v) const
{
	return VECTOR3(
		y*v.z - z*v.y,
		z*v.x - x*v.z,
		x*v.y - y*v.x
		);
}

#pragma endregion // VECTOR3

#pragma region VECTOR4
VECTOR4::VECTOR4()
	: x(0.f)
	, y(0.f)
	, z(0.f)
	, w(1.f)
{
}

VECTOR4::VECTOR4(float x, float y, float z, float w)
	: x(x)
	, y(y)
	, z(z)
	, w(w)
{
}
VECTOR4::VECTOR4(const VECTOR2& v)
	: x(v.x)
	, y(v.y)
	, z(0.f)
	, w(1.f)
{
}

VECTOR4::VECTOR4(const VECTOR3& v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
	, w(1.f)
{
}


VECTOR4::~VECTOR4()
{
}

VECTOR4& VECTOR4::operator = (const VECTOR4& v)
{
	if (this != &v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	return *this;
}


VECTOR4 VECTOR4::operator-()const
{
	return VECTOR4(-x, -y, -z, -w);
}

VECTOR4& VECTOR4::negate()
{
	x = -x;
	y = -y;
	z = -z;
	w = -w;
	return *this;
}

float VECTOR4::length() const
{
	return std::sqrtf(x*x + y*y + z*z + w*w);
}

VECTOR4& VECTOR4::normalize()
{
	float mag = 1.f / length();
	x *= mag;
	y *= mag;
	z *= mag;
	w *= mag;
	return *this;
}

#pragma endregion // VECTOR4