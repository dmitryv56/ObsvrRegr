#include <iostream>
#include <string>
#include <vector>
#include "concretRA.h"
#include "executor.h"


using namespace std;

int main(int argc, char * argv[])
{
  
	concretRA ra;
	
	executor cntsRA( 0, "b0");
	executor linRA( 1,"b0 +b1*x");
	executor quRA( 2,"b0+b1*x +b2*x**2");

	// 

	ra.Attach(&linRA);
	ra.Attach(&quRA);

	// Now let try regression executing, this should run executer automatically

	ra.ChangeData(0); 

	// Now quadratic regression is not interested
	ra.Detach(&quRA);

	ra.ChangeData(0);

	getchar();




	return 0;

}