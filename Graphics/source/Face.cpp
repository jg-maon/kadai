#include "Face.h"

Face::Face()
	: m_verticies()
{

}

// ���_�̒ǉ�
void Face::AddVertex(const VECTOR4& vertex)
{
	m_verticies.push_back(vertex);
}

// ���_�̎擾
const VECTOR4& Face::GetVertexAt(unsigned int index) const
{
	return m_verticies[index];
}

// ���_���̎擾
size_t Face::GetVertexNum() const
{
	return m_verticies.size();
}