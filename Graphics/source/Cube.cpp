#include "Cube.h"

Cube::Cube(float size)
	: m_verticies()
	, m_faces()
{
	_GenerateVerticies(size);
	_GenerateFaces();
}

Cube::~Cube()
{
}

// ���_�̎擾
const std::vector<VECTOR4>& Cube::GetVerticies() const
{
	return m_verticies;
}

// �ʂ̎擾
const std::vector<Face>& Cube::GetFaces() const
{
	return m_faces;
}


// ���_�̍쐬
bool Cube::_GenerateVerticies(float size)
{
	if (!m_verticies.empty())
	{
		return false;
	}
	float half = size / 2.f;

	m_verticies.emplace_back(-half, -half, -half, 1.f);	// 0
	m_verticies.emplace_back(-half, -half, +half, 1.f);	// 1
	m_verticies.emplace_back(+half, -half, +half, 1.f);	// 2
	m_verticies.emplace_back(+half, -half, -half, 1.f);	// 3
	m_verticies.emplace_back(-half, +half, -half, 1.f);	// 4
	m_verticies.emplace_back(-half, +half, +half, 1.f);	// 5
	m_verticies.emplace_back(+half, +half, +half, 1.f);	// 6
	m_verticies.emplace_back(+half, +half, -half, 1.f);	// 7

	return true;
}


// �ʂ̍쐬
bool Cube::_GenerateFaces()
{
	if (!m_faces.empty())
	{
		return false;
	}
	if (!m_verticies.empty())
	{
		return false;
	}

	const int FACE_NUM = 6 * 2;	// �O�p�|���S���Ȃ̂� *2
	const int VERTEX_NUM = 3;
	int vertexIndex[FACE_NUM][VERTEX_NUM] = {
		{ 0, 1, 2 },	// ��
		{ 2, 3, 0 },	// ��

		{ 0, 4, 5 },	// ��
		{ 5, 1, 0 },	// ��

		{ 4, 5, 6 },	// ��
		{ 6, 7, 4 },	// ��
		
		{ 5, 6, 2 },	// ��
		{ 2, 1, 5 },	// ��
		
		{ 6, 2, 3 },	// �E
		{ 3, 7, 6 },	// �E
		
		{ 7, 3, 0 },	// �O
		{ 0, 4, 7 },	// �O
	};

	for (int i = 0; i < FACE_NUM; ++i)
	{
		Face face;
		// ���_�̒ǉ�
		for (int j = 0; j < VERTEX_NUM; ++j)
		{
			face.AddVertex(m_verticies[vertexIndex[i][j]]);
		}
		// �ʂƂ��Ēǉ�
		m_faces.push_back(face);
	}

	return true;
}