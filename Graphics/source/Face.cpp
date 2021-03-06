#include "Face.h"

Face::Face()
	: m_vertices()
{

}

// 頂点の追加
void Face::AddVertex(const VECTOR4& vertex)
{
	m_vertices.push_back(vertex);
}

// 頂点の取得
const VECTOR4& Face::GetVertexAt(unsigned int index) const
{
	return m_vertices[index];
}

// 頂点数の取得
size_t Face::GetVertexNum() const
{
	return m_vertices.size();
}