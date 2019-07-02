#pragma once
#include <vector>
#include <list>
#include "executor.h"


class AbstractRA
{
// Lets keep a track af all ececutors we have observing
	std::vector <executor*> list;

	
public:
	void Attach(executor *executorRA);
	void Detach(executor *executorRA);
	void Notify(int tag, std::vector <float >  x, std::vector <float > y);
	
};

