#include "Face.h"

Face::Face()
	: m_vertices()
{

}

// ���_�̒ǉ�
void Face::AddVertex(const VECTOR4& vertex)
{
	m_vertices.push_back(vertex);
}

// ���_�̎擾
const VECTOR4& Face::GetVertexAt(unsigned int index) const
{
	return m_vertices[index];
}

// ���_���̎擾
size_t Face::GetVertexNum() const
{
	return m_vertices.size();
}