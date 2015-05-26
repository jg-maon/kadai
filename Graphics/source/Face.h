#ifndef ___Face_h___
#define ___Face_h___

#include "Math.h"
#include <vector>

// 面クラス
class Face
{
public:
	Face();

	/**
		@brief		頂点の追加
		@param[in]	vertex	頂点
		@return		なし
	*/
	void AddVertex(const VECTOR4& vertex);

	/**
		@brief		頂点の取得
		@param[in]	index	頂点インデックス
		@return		頂点
	*/
	const VECTOR4& GetVertexAt(unsigned int index) const;


	/**
		@brief		頂点数の取得
		@param[in]	なし
		@return		頂点数
	*/
	size_t GetVertexNum() const;

private:
	std::vector<VECTOR4>	m_vertices;	//!< 頂点

};

#endif // ___Face_h___