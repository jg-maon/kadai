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
	
#pragma region 演算子のオーバーロード(ベクトル)
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル
	*/
	VECTOR2 operator + (const VECTOR2& v) const { return VECTOR2(x + v.x, y + v.y);	}
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル
	*/
	VECTOR2 operator - (const VECTOR2& v) const { return VECTOR2(x - v.x, y - v.y);	}
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR2 operator * (const VECTOR2& v) const { return VECTOR2(x * v.x, y * v.y);	}
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR2 operator / (const VECTOR2& v) const { return VECTOR2(x / v.x, y / v.y);	}

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR2& operator += (const VECTOR2& v) { x += v.x; y += v.y; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR2& operator -= (const VECTOR2& v) { x -= v.x; y -= v.y; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR2& operator *= (const VECTOR2& v) { x *= v.x; y *= v.y; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR2& operator /= (const VECTOR2& v) { x /= v.x; y /= v.y; return *this; }

#pragma endregion	// 演算子のオーバーロード(ベクトル)

#pragma region 演算子のオーバーロード(定数)
	/**
		@brief		=演算子のオーバーロード(代入)
		@param[in]	v	ベクトル
		@return		代入した自身
	*/
	VECTOR2& operator = (const float c)	{ x = c; y = c; return *this; }
		
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル
	*/
	VECTOR2 operator + (const float c) const { return VECTOR2(x + c, y + c);	}
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル
	*/
	VECTOR2 operator - (const float c) const { return VECTOR2(x - c, y - c);	}
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR2 operator * (const float c) const { return VECTOR2(x * c, y * c);	}
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR2 operator / (const float c) const { return VECTOR2(x / c, y / c);	}

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR2& operator += (const float c) { x += c; y += c; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR2& operator -= (const float c) { x -= c; y -= c; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR2& operator *= (const float c) { x *= c; y *= c; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR2& operator /= (const float c) { x /= c; y /= c; return *this; }
#pragma endregion	// 演算子のオーバーロード(定数)

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
	
#pragma region 演算子のオーバーロード(ベクトル)
	
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル
	*/
	VECTOR3 operator + (const VECTOR& v) const { return VECTOR3(x + v.x, y + v.y, z + v.z);	}
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル
	*/
	VECTOR3 operator - (const VECTOR& v) const { return VECTOR3(x - v.x, y - v.y, z - v.z);	}
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR3 operator * (const VECTOR& v) const { return VECTOR3(x * v.x, y * v.y, z * v.z);	}
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR3 operator / (const VECTOR& v) const { return VECTOR3(x / v.x, y / v.y, z / v.z);	}

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR3& operator += (const VECTOR& v) { x += v.x; y += v.y; z += v.z; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR3& operator -= (const VECTOR& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR3& operator *= (const VECTOR& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR3& operator /= (const VECTOR& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

#pragma endregion	// 演算子のオーバーロード(ベクトル)

#pragma region 演算子のオーバーロード(定数)
	/**
		@brief		=演算子のオーバーロード(代入)
		@param[in]	v	ベクトル
		@return		代入した自身
	*/
	VECTOR3& operator = (const float c)	{ x = c; y = c; z = c; return *this; }
		
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル
	*/
	VECTOR3 operator + (const float c) const { return VECTOR3(x + c, y + c, z + c);	}
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル
	*/
	VECTOR3 operator - (const float c) const { return VECTOR3(x - c, y - c, z - c);	}
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR3 operator * (const float c) const { return VECTOR3(x * c, y * c, z * c);	}
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR3 operator / (const float c) const { return VECTOR3(x / c, y / c, z / c);	}

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR3& operator += (const float c) { x += c; y += c; z += c; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR3& operator -= (const float c) { x -= c; y -= c; z -= c; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR3& operator *= (const float c) { x *= c; y *= c; z *= c; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR3& operator /= (const float c) { x /= c; y /= c; z /= c; return *this; }
#pragma endregion	// 演算子のオーバーロード(定数)

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
	
#pragma region 演算子のオーバーロード(ベクトル)
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル
	*/
	VECTOR4 operator + (const VECTOR4& v) const { return VECTOR4(x + v.x, y + v.y, z + v.z, w + v.w); }
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル
	*/
	VECTOR4 operator - (const VECTOR4& v) const { return VECTOR4(x - v.x, y - v.y, z - v.z, w - v.w); }
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR4 operator * (const VECTOR4& v) const { return VECTOR4(x * v.x, y * v.y, z*v.z, w*v.w); }
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル
	*/
	VECTOR4 operator / (const VECTOR4& v) const { return VECTOR4(x / v.x, y / v.y, z / v.z, w / v.w); }

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	v	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR4& operator += (const VECTOR4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	v	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR4& operator -= (const VECTOR4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR4& operator *= (const VECTOR4& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	v	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR4& operator /= (const VECTOR4& v) { x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; }

#pragma endregion	// 演算子のオーバーロード(ベクトル)

#pragma region 演算子のオーバーロード(定数)
	/**
		@brief		=演算子のオーバーロード(代入)
		@param[in]	v	ベクトル
		@return		代入した自身
	*/
	VECTOR4& operator = (const float c)	{ x = c; y = c; z = c; w = c; return *this; }
		
	/**
		@brief		+演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル
	*/
	VECTOR4 operator + (const float c) const { return VECTOR4(x + c, y + c, z + c, w + c); }
		
	/**
		@brief		-演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル
	*/
	VECTOR4 operator - (const float c) const { return VECTOR4(x - c, y - c, z - c, w - c); }
		
	/**
		@brief		*演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR4 operator * (const float c) const { return VECTOR4(x * c, y * c, z*c, w*c); }
		
	/**
		@brief		/演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル
	*/
	VECTOR4 operator / (const float c) const { return VECTOR4(x / c, y / c, z / c, w / c); }

		
	/**
		@brief		+=演算子のオーバーロード(定数加算)
		@param[in]	c	定数
		@return		定数加算後のベクトル自身
	*/
	VECTOR4& operator += (const float c) { x += c; y += c; z += c; w += c; return *this; }
		
	/**
		@brief		-=演算子のオーバーロード(定数減算)
		@param[in]	c	定数
		@return		定数減算後のベクトル自身
	*/
	VECTOR4& operator -= (const float c) { x -= c; y -= c; z -= c; w -= c; return *this; }
		
	/**
		@brief		*=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR4& operator *= (const float c) { x *= c; y *= c; z *= c; w *= c; return *this; }
		
	/**
		@brief		/=演算子のオーバーロード(定数倍)
		@param[in]	c	定数
		@return		定数倍後のベクトル自身
	*/
	VECTOR4& operator /= (const float c) { x /= c; y /= c; z /= c; w /= c; return *this; }
#pragma endregion	// 演算子のオーバーロード(定数)

	float x;
	float y;
	float z;
	float w;
};


#endif	// ___Math_h___