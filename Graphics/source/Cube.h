#ifndef ___Cube_h___
#define ___Cube_h___

#include "Math.h"
#include "Face.h"
#include <vector>


class Cube
{
public:
	/**
		@param[in]	size	1�ӂ̒���
	*/
	explicit Cube(float size);

	virtual ~Cube();

	/**
		@brief		���_�̎擾
		@param[in]	�Ȃ�
		@return		���_
	*/
	const std::vector<VECTOR4>& GetVertices() const;

	/**
		@brief		�ʂ̎擾
		@param[in]	�Ȃ�
		@return		��
	*/
	const std::vector<Face>& GetFaces() const;

private:
	/**
		@brief		���_�̍쐬
		@param[in]	size	1�ӂ̒���
		@return		�쐬������
		@retval		true	�쐬
		@retval		false	���s(���ɍ쐬����Ă���)
	*/
	bool _GenerateVertices(float size);

	/**
		@brief		�ʂ̍쐬
		@param[in]	�Ȃ�
		@return		�쐬������
		@retval		true	�쐬
		@retval		false	���s(���ɍ쐬����Ă���)
	*/
	bool _GenerateFaces();

private:
	std::vector<VECTOR4> m_vertices;	//!< ���_

	std::vector<Face>	m_faces;		//!< ��
};

#endif // ___Cube_h___