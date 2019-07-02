#include "AbstractRA.h"
#include <algorithm>

using namespace std;



void AbstractRA::Attach(executor *executorRA)
{
	list.push_back(executorRA);
}

void AbstractRA::Detach(executor *executorRA)
{

	list.erase(std::remove(list.begin(), list.end(), executorRA), list.end());
}

void AbstractRA::Notify(int tag, std::vector <float >  x, std::vector <float > y)
{
	for (vector<executor*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if (*iter != 0)
		{
			(*iter)->Update( tag, x,y  );
		}
	}
}
