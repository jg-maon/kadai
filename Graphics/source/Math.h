#ifndef ___Math_h___
#define ___Math_h___

#include "DxLib.h"
namespace ns_Math
{
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

		float length() const;

		VECTOR2& normalize();


		float dot(const VECTOR2& v) const;

		float cross(const VECTOR2& v) const;

#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)
		/**
			@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR2 operator + (const VECTOR2& v) const { return VECTOR2(x + v.x, y + v.y); }

		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR2 operator - (const VECTOR2& v) const { return VECTOR2(x - v.x, y - v.y); }

		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR2 operator * (const VECTOR2& v) const { return VECTOR2(x * v.x, y * v.y); }

		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR2 operator / (const VECTOR2& v) const { return VECTOR2(x / v.x, y / v.y); }


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
		VECTOR2 operator + (const float c) const { return VECTOR2(x + c, y + c); }

		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR2 operator - (const float c) const { return VECTOR2(x - c, y - c); }

		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR2 operator * (const float c) const { return VECTOR2(x * c, y * c); }

		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR2 operator / (const float c) const { return VECTOR2(x / c, y / c); }


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

		float length() const;

		VECTOR3& normalize();
		
		float dot(const VECTOR3& v) const;

		VECTOR3 cross(const VECTOR3& v) const;

#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)

		/**
			@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR3 operator + (const VECTOR& v) const { return VECTOR3(x + v.x, y + v.y, z + v.z); }

		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR3 operator - (const VECTOR& v) const { return VECTOR3(x - v.x, y - v.y, z - v.z); }

		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR3 operator * (const VECTOR& v) const { return VECTOR3(x * v.x, y * v.y, z * v.z); }

		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR3 operator / (const VECTOR& v) const { return VECTOR3(x / v.x, y / v.y, z / v.z); }


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
		VECTOR3 operator + (const float c) const { return VECTOR3(x + c, y + c, z + c); }

		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g��
			*/
		VECTOR3 operator - (const float c) const { return VECTOR3(x - c, y - c, z - c); }

		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR3 operator * (const float c) const { return VECTOR3(x * c, y * c, z * c); }

		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
			*/
		VECTOR3 operator / (const float c) const { return VECTOR3(x / c, y / c, z / c); }


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

		float length() const;

		VECTOR4& normalize();



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


	/**
		@brief		�P�ʍs��̍쐬
		@param[out]	out	�s��
		@return		�s��̎Q��
	*/
	inline MATRIX& CreateIdentityMatrix(MATRIX& out)
	{
		out.m[0][0] = 1.f;	out.m[0][1] = 0.f;	out.m[0][2] = 0.f;	out.m[0][3] = 0.f;
		out.m[1][0] = 0.f;	out.m[1][1] = 1.f;	out.m[1][2] = 0.f;	out.m[1][3] = 0.f;
		out.m[2][0] = 0.f;	out.m[2][1] = 0.f;	out.m[2][2] = 1.f;	out.m[2][3] = 0.f;
		out.m[3][0] = 0.f;	out.m[3][1] = 0.f;	out.m[3][2] = 0.f;	out.m[3][3] = 1.f;

		return out;
	}

	inline MATRIX& CreateTranslationMatrix(MATRIX& out, float x, float y, float z)
	{
		out.m[0][0] = 1.f;	out.m[0][1] = 0.f;	out.m[0][2] = 0.f;	out.m[0][3] = 0.f;
		out.m[1][0] = 0.f;	out.m[1][1] = 1.f;	out.m[1][2] = 0.f;	out.m[1][3] = 0.f;
		out.m[2][0] = 0.f;	out.m[2][1] = 0.f;	out.m[2][2] = 1.f;	out.m[2][3] = 0.f;
		out.m[3][0] = x;	out.m[3][1] = y;	out.m[3][2] = z;	out.m[3][3] = 1.f;

		return out;
	}

	/**
		@brief		�������e�s��̍쐬
		@param[out]	out		�s��
		@param[in]	width	�r���[�{�����[���̕�
		@param[in]	height	�r���[�{�����[���̍���
		@param[in]	nearZ	�ߕ��ʂ܂ł̋���
		@param[in]	farZ	�����ʂ܂ł̋���
		@return		�s��̎Q��
	*/
	inline MATRIX& CreatePerspectiveLH(MATRIX& out, float width, float height, float nearZ, float farZ)
	{
		out.m[0][0] = (2.f*nearZ) / width;	out.m[0][1] = 0.f;					out.m[0][2] = 0.f;								out.m[0][3] = 0.f;
		out.m[1][0] = 0.f;					out.m[1][1] = (2.f*nearZ) / height;	out.m[1][2] = 0.f;								out.m[1][3] = 0.f;
		out.m[2][0] = 0.f;					out.m[2][1] = 0.f;					out.m[2][2] = farZ / (farZ - nearZ);			out.m[2][3] = 1.f;
		out.m[3][0] = 0.f;					out.m[3][1] = 0.f;					out.m[3][2] = (nearZ*farZ) / (farZ - nearZ);	out.m[3][3] = 0.f;
		
		return out;
	}
	
	/**
		@brief		�������e�s��̍쐬
		@param[out]	out		�s��
		@param[in]	width	�r���[�{�����[���̕�
		@param[in]	height	�r���[�{�����[���̍���
		@param[in]	nearZ	�ߕ��ʂ܂ł̋���
		@param[in]	farZ	�����ʂ܂ł̋���
		@return		�s��̎Q��
	*/
	inline MATRIX& CreatePerspectiveRH(MATRIX& out, float width, float height, float nearZ, float farZ)
	{
		out.m[0][0] = (2.f*nearZ) / width;	out.m[0][1] = 0.f;					out.m[0][2] = 0.f;								out.m[0][3] = 0.f;
		out.m[1][0] = 0.f;					out.m[1][1] = (2.f*nearZ) / height;	out.m[1][2] = 0.f;								out.m[1][3] = 0.f;
		out.m[2][0] = 0.f;					out.m[2][1] = 0.f;					out.m[2][2] = farZ / (nearZ - farZ);			out.m[2][3] = -1.f;
		out.m[3][0] = 0.f;					out.m[3][1] = 0.f;					out.m[3][2] = (nearZ*farZ) / (nearZ - farZ);	out.m[3][3] = 0.f;
		
		return out;
	}

	inline MATRIX& CreateLookAtLH(MATRIX& out, const VECTOR3& eye, const VECTOR3& at, const VECTOR3& up)
	{
		VECTOR3 zaxis = (at - eye);
		zaxis.normalize();
		VECTOR3 xaxis = (up.cross(zaxis));
		xaxis.normalize();
		VECTOR3 yaxis = zaxis.cross(xaxis);
		out.m[0][0] = xaxis.x;				out.m[0][1] = yaxis.x;          out.m[0][2] = zaxis.x;				out.m[0][3] = 0.f;
		out.m[1][0] = xaxis.y;				out.m[1][1] = yaxis.y;          out.m[1][2] = zaxis.y;				out.m[1][3] = 0.f;
		out.m[2][0] = xaxis.z;				out.m[2][1] = yaxis.z;          out.m[2][2] = zaxis.z;				out.m[2][3] = 0.f;
		out.m[3][0] = -(xaxis.dot(eye));	out.m[3][1] = -yaxis.dot(eye);	out.m[3][2] = -zaxis.dot(eye);		out.m[3][3] = 1.f;


		return out;
	}


	/**
		@brief		�s��1 * �s��2
		@param[out]	out	��������
		@param[in]	m1	�s��1
		@param[in]	m2	�s��2
		@return		�������ʂ̎Q��
	*/
	inline MATRIX& MultiplyMatrix(MATRIX& out, MATRIX& m1, MATRIX& m2)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					out.m[i][j] = m1.m[i][k] * m2.m[k][j];
				}
			}
		}
		return out;
	}

	/**
		@brief	3�����x�N�g����4�����x�N�g���Ɋg�����A�ϊ�
		@param[out]	out	�ϊ�����
		@param[in]	v	�x�N�g��
		@param[in]	mat	�s��
		@return		�ϊ����ʂ̃x�N�g���̎Q��
	*/
	inline VECTOR3& Vector3Transform(VECTOR3& out, const VECTOR3& v, const MATRIX& mat)
	{
		float v4[4] = { v.x, v.y, v.z, 1.0f };
		float rv4[4] = { 0.0f };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rv4[i] += v4[j] * mat.m[j][i];
			}
		}
		out.x = rv4[0];
		out.y = rv4[1];
		out.z = rv4[2];
		
		return out;
	}

	/**
		@brief	3�����x�N�g����4�����x�N�g���Ɋg�����A�ϊ�
		@param[out]	out	�ϊ�����
		@param[in]	mat	�s��
		@param[in]	v	�x�N�g��
		@return		�ϊ����ʂ̃x�N�g���̎Q��
	*/
	inline VECTOR3& Vector3Transform(VECTOR3& out, const MATRIX& mat, const VECTOR3& v)
	{
		float v4[4] = { v.x, v.y, v.z, 1.0f };
		float rv4[4] = { 0.0f };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rv4[i] += mat.m[i][j] * v4[j];
			}
		}

		out.x = rv4[0];
		out.y = rv4[1];
		out.z = rv4[2];

		return out;
	}
	
	/**
		@brief	4�����x�N�g�� * �s��
		@param[put]	out	�ϊ�����
		@param[in]	v	�x�N�g��
		@param[in]	mat	�s��
		@return		�ϊ����ʂ̃x�N�g���̎Q��
	*/
	inline VECTOR4& Vector4Transform(VECTOR4& out, const VECTOR4& v, const MATRIX& mat)
	{
		float v4[4] = { v.x, v.y, v.z, 1.0f };
		float rv4[4] = { 0.0f };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rv4[i] += v4[j] * mat.m[j][i];
			}
		}
		out.x = rv4[0];
		out.y = rv4[1];
		out.z = rv4[2];
		out.w = rv4[3];

		return out;
	}

	/**
		@brief	�s�� * 4�����x�N�g��
		@param[put]	out	�ϊ�����
		@param[in]	mat	�s��
		@param[in]	v	�x�N�g��
		@return		�ϊ����ʂ̃x�N�g���̎Q��
	*/
	inline VECTOR4 Vector4Transform(VECTOR4& out, const MATRIX& mat, const VECTOR4& v)
	{
		float v4[4] = { v.x, v.y, v.z, v.w };
		float rv4[4] = { 0.0f };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rv4[i] += mat.m[i][j] * v4[j];
			}
		}
		out.x = rv4[0];
		out.y = rv4[1];
		out.z = rv4[2];
		out.w = rv4[3];

		return out;
	}

}	// namespace ns_Math
using namespace ns_Math;
#endif	// ___Math_h___