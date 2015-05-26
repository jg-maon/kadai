#ifndef ___Cube_h___
#define ___Cube_h___

#include "Math.h"
#include "Face.h"
#include <vector>


class Cube
{
public:
	/**
		@param[in]	size	1辺の長さ
	*/
	explicit Cube(float size);

	virtual ~Cube();

	/**
		@brief		頂点の取得
		@param[in]	なし
		@return		頂点
	*/
	const std::vector<VECTOR4>& GetVertices() const;

	/**
		@brief		面の取得
		@param[in]	なし
		@return		面
	*/
	const std::vector<Face>& GetFaces() const;

private:
	/**
		@brief		頂点の作成
		@param[in]	size	1辺の長さ
		@return		作成したか
		@retval		true	作成
		@retval		false	失敗(既に作成されている)
	*/
	bool _GenerateVertices(float size);

	/**
		@brief		面の作成
		@param[in]	なし
		@return		作成したか
		@retval		true	作成
		@retval		false	失敗(既に作成されている)
	*/
	bool _GenerateFaces();

private:
	std::vector<VECTOR4> m_vertices;	//!< 頂点

	std::vector<Face>	m_faces;		//!< 面
};

#endif // ___Cube_h___