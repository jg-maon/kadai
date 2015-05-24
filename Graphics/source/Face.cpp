#include "Face.h"

Face::Face()
	: m_verticies()
{

}

// 頂点の追加
void Face::AddVertex(const VECTOR4& vertex)
{
	m_verticies.push_back(vertex);
}

// 頂点の取得
const VECTOR4& Face::GetVertexAt(unsigned int index) const
{
	return m_verticies[index];
}

// 頂点数の取得
size_t Face::GetVertexNum() const
{
	return m_verticies.size();
}