#include "concretRA.h"


concretRA::concretRA()
{
}


concretRA::~concretRA()
{
}

void concretRA::ChangeData(int tag)
{
	for (int i = 0; i < 128; i++)
	{
		float v = float(i*i % 31);
		this->x.push_back ( v);
		
	}
	for (std::vector<float>::const_iterator k = x.begin(); k != x.end(); ++k)
	{
		float v = *k;
		y.push_back(1.05 - 0.5*v);
	}
	this->Notify(tag, this->x, this->y);
}
