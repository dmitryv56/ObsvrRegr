#pragma once
#include "AbstractRA.h"
class concretRA :
	public AbstractRA
{
	std::vector <float > x;
	std::vector <float > y;
public:

	void ChangeData(int tag );
	concretRA();
	~concretRA();
};

