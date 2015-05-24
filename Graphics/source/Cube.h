#ifndef ___Cube_h___
#define ___Cube_h___

#include "Math.h"
#include <vector>

class Cube
{
public:
	/**
		@param[in]	size	1•Ó‚Ì’·‚³
	*/
	explicit Cube(float size);

private:
	std::vector<VECTOR4> m_verticies;	//!< ’¸“_
};

#endif // ___Cube_h___