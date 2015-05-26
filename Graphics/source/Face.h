#ifndef ___Face_h___
#define ___Face_h___

#include "Math.h"
#include <vector>

// �ʃN���X
class Face
{
public:
	Face();

	/**
		@brief		���_�̒ǉ�
		@param[in]	vertex	���_
		@return		�Ȃ�
	*/
	void AddVertex(const VECTOR4& vertex);

	/**
		@brief		���_�̎擾
		@param[in]	index	���_�C���f�b�N�X
		@return		���_
	*/
	const VECTOR4& GetVertexAt(unsigned int index) const;


	/**
		@brief		���_���̎擾
		@param[in]	�Ȃ�
		@return		���_��
	*/
	size_t GetVertexNum() const;

private:
	std::vector<VECTOR4>	m_vertices;	//!< ���_

};

#endif // ___Face_h___