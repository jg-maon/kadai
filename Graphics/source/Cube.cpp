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

// 頂点の取得
const std::vector<VECTOR4>& Cube::GetVerticies() const
{
	return m_verticies;
}

// 面の取得
const std::vector<Face>& Cube::GetFaces() const
{
	return m_faces;
}


// 頂点の作成
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


// 面の作成
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

	const int FACE_NUM = 6 * 2;	// 三角ポリゴンなので *2
	const int VERTEX_NUM = 3;
	int vertexIndex[FACE_NUM][VERTEX_NUM] = {
		{ 0, 1, 2 },	// 下
		{ 2, 3, 0 },	// 下

		{ 0, 4, 5 },	// 左
		{ 5, 1, 0 },	// 左

		{ 4, 5, 6 },	// 上
		{ 6, 7, 4 },	// 上
		
		{ 5, 6, 2 },	// 奥
		{ 2, 1, 5 },	// 奥
		
		{ 6, 2, 3 },	// 右
		{ 3, 7, 6 },	// 右
		
		{ 7, 3, 0 },	// 前
		{ 0, 4, 7 },	// 前
	};

	for (int i = 0; i < FACE_NUM; ++i)
	{
		Face face;
		// 頂点の追加
		for (int j = 0; j < VERTEX_NUM; ++j)
		{
			face.AddVertex(m_verticies[vertexIndex[i][j]]);
		}
		// 面として追加
		m_faces.push_back(face);
	}

	return true;
}