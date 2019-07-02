#pragma once
class IObserver
{
public:
	virtual void Update(int tag, std::vector<float>x, std::vector <float> y) = 0;
};

