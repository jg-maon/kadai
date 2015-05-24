#include "Face.h"

Face::Face()
	: m_verticies()
{

}

// ’¸“_‚Ì’Ç‰Á
void Face::AddVertex(const VECTOR4& vertex)
{
	m_verticies.push_back(vertex);
}

// ’¸“_‚Ìæ“¾
const VECTOR4& Face::GetVertexAt(unsigned int index) const
{
	return m_verticies[index];
}

// ’¸“_”‚Ìæ“¾
size_t Face::GetVertexNum() const
{
	return m_verticies.size();
}