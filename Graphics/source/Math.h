#ifndef ___Math_h___
#define ___Math_h___

#include "DxLib.h"

struct VECTOR3;
struct VECTOR4;

struct VECTOR2
{
	VECTOR2();
	VECTOR2(float x, float y);
	explicit VECTOR2(const VECTOR3& v);
	explicit VECTOR2(const VECTOR4& v);
	~VECTOR2();

	VECTOR2& operator=(const VECTOR2& v);
	VECTOR2 operator-()const;


	VECTOR2& negate();
	
#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR2 operator + (const VECTOR2& v) const { return VECTOR2(x + v.x, y + v.y);	}
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR2 operator - (const VECTOR2& v) const { return VECTOR2(x - v.x, y - v.y);	}
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR2 operator * (const VECTOR2& v) const { return VECTOR2(x * v.x, y * v.y);	}
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR2 operator / (const VECTOR2& v) const { return VECTOR2(x / v.x, y / v.y);	}

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR2& operator += (const VECTOR2& v) { x += v.x; y += v.y; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR2& operator -= (const VECTOR2& v) { x -= v.x; y -= v.y; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR2& operator *= (const VECTOR2& v) { x *= v.x; y *= v.y; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR2& operator /= (const VECTOR2& v) { x /= v.x; y /= v.y; return *this; }

#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�x�N�g��)

#pragma region ���Z�q�̃I�[�o�[���[�h(�萔)
	/**
		@brief		=���Z�q�̃I�[�o�[���[�h(���)
		@param[in]	v	�x�N�g��
		@return		����������g
	*/
	VECTOR2& operator = (const float c)	{ x = c; y = c; return *this; }
		
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR2 operator + (const float c) const { return VECTOR2(x + c, y + c);	}
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR2 operator - (const float c) const { return VECTOR2(x - c, y - c);	}
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR2 operator * (const float c) const { return VECTOR2(x * c, y * c);	}
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR2 operator / (const float c) const { return VECTOR2(x / c, y / c);	}

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR2& operator += (const float c) { x += c; y += c; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR2& operator -= (const float c) { x -= c; y -= c; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR2& operator *= (const float c) { x *= c; y *= c; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR2& operator /= (const float c) { x /= c; y /= c; return *this; }
#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�萔)

	float x;
	float y;
};

struct VECTOR3 : public ::DxLib::VECTOR
{
	VECTOR3();

	VECTOR3(float x, float y, float z);
	explicit VECTOR3(const VECTOR2& v);
	explicit VECTOR3(const VECTOR4& v);
	explicit VECTOR3(const DxLib::VECTOR& v);

	~VECTOR3();

	VECTOR3& operator = (DxLib::VECTOR& v);


	VECTOR3 operator-()const;

	VECTOR3& negate();
	
#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)
	
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR3 operator + (const VECTOR& v) const { return VECTOR3(x + v.x, y + v.y, z + v.z);	}
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR3 operator - (const VECTOR& v) const { return VECTOR3(x - v.x, y - v.y, z - v.z);	}
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR3 operator * (const VECTOR& v) const { return VECTOR3(x * v.x, y * v.y, z * v.z);	}
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR3 operator / (const VECTOR& v) const { return VECTOR3(x / v.x, y / v.y, z / v.z);	}

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR3& operator += (const VECTOR& v) { x += v.x; y += v.y; z += v.z; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR3& operator -= (const VECTOR& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR3& operator *= (const VECTOR& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR3& operator /= (const VECTOR& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�x�N�g��)

#pragma region ���Z�q�̃I�[�o�[���[�h(�萔)
	/**
		@brief		=���Z�q�̃I�[�o�[���[�h(���)
		@param[in]	v	�x�N�g��
		@return		����������g
	*/
	VECTOR3& operator = (const float c)	{ x = c; y = c; z = c; return *this; }
		
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR3 operator + (const float c) const { return VECTOR3(x + c, y + c, z + c);	}
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR3 operator - (const float c) const { return VECTOR3(x - c, y - c, z - c);	}
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR3 operator * (const float c) const { return VECTOR3(x * c, y * c, z * c);	}
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR3 operator / (const float c) const { return VECTOR3(x / c, y / c, z / c);	}

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR3& operator += (const float c) { x += c; y += c; z += c; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR3& operator -= (const float c) { x -= c; y -= c; z -= c; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR3& operator *= (const float c) { x *= c; y *= c; z *= c; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR3& operator /= (const float c) { x /= c; y /= c; z /= c; return *this; }
#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�萔)

};


struct VECTOR4
{
	VECTOR4();
	VECTOR4(float x, float y, float z, float w = 1.0f);
	explicit VECTOR4(const VECTOR2& v);
	explicit VECTOR4(const VECTOR3& v);
	~VECTOR4();

	VECTOR4& operator=(const VECTOR4& v);
	VECTOR4 operator-()const;


	VECTOR4& negate();
	
#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR4 operator + (const VECTOR4& v) const { return VECTOR4(x + v.x, y + v.y, z + v.z, w + v.w); }
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR4 operator - (const VECTOR4& v) const { return VECTOR4(x - v.x, y - v.y, z - v.z, w - v.w); }
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR4 operator * (const VECTOR4& v) const { return VECTOR4(x * v.x, y * v.y, z*v.z, w*v.w); }
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR4 operator / (const VECTOR4& v) const { return VECTOR4(x / v.x, y / v.y, z / v.z, w / v.w); }

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR4& operator += (const VECTOR4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	v	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR4& operator -= (const VECTOR4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR4& operator *= (const VECTOR4& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	v	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR4& operator /= (const VECTOR4& v) { x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; }

#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�x�N�g��)

#pragma region ���Z�q�̃I�[�o�[���[�h(�萔)
	/**
		@brief		=���Z�q�̃I�[�o�[���[�h(���)
		@param[in]	v	�x�N�g��
		@return		����������g
	*/
	VECTOR4& operator = (const float c)	{ x = c; y = c; z = c; w = c; return *this; }
		
	/**
		@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR4 operator + (const float c) const { return VECTOR4(x + c, y + c, z + c, w + c); }
		
	/**
		@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g��
	*/
	VECTOR4 operator - (const float c) const { return VECTOR4(x - c, y - c, z - c, w - c); }
		
	/**
		@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR4 operator * (const float c) const { return VECTOR4(x * c, y * c, z*c, w*c); }
		
	/**
		@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g��
	*/
	VECTOR4 operator / (const float c) const { return VECTOR4(x / c, y / c, z / c, w / c); }

		
	/**
		@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR4& operator += (const float c) { x += c; y += c; z += c; w += c; return *this; }
		
	/**
		@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
		@param[in]	c	�萔
		@return		�萔���Z��̃x�N�g�����g
	*/
	VECTOR4& operator -= (const float c) { x -= c; y -= c; z -= c; w -= c; return *this; }
		
	/**
		@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR4& operator *= (const float c) { x *= c; y *= c; z *= c; w *= c; return *this; }
		
	/**
		@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
		@param[in]	c	�萔
		@return		�萔�{��̃x�N�g�����g
	*/
	VECTOR4& operator /= (const float c) { x /= c; y /= c; z /= c; w /= c; return *this; }
#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�萔)

	float x;
	float y;
	float z;
	float w;
};


#endif	// ___Math_h___