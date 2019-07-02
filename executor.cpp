#include "executor.h"

/*
executor::executor(int tag, std::string name)
{
	this->name = name;
	this->tag = tag;
}
*/

/*
void executor::Update(int tag, std::vector<float >x, std::vector <float > y)
{
	// Lets print on console just to test the working
	std::cout << "name is " << name << " tag is " << tag << std::endl;
	switch (this->tag)
	{
	case 0:
		this->constRA(y);
		break;
	case 1:
		this->linearRA(x, y);
		break;
	case 2:
		this->quadraticRA(x, y);
		break;
	}

	
	
}
*/
void executor::constRA(std::vector<float > y)
{
	this->b0 = 1.0;

	this->printRegr();
}
void executor::linearRA(std::vector<float >x, std::vector<float > y)
{
	this->b0 = -0.5;
	this->b1 = 0.25;

	std::vector<float>::const_iterator ix, iy;
	float xtx = 0.0;
	float xty = 0.0;
	for (ix = x.begin(), iy = y.begin(); ix != x.end() && iy != y.end(); ++ix, ++iy)
	{
		float x1 = (*ix);
		float y1 = (*iy);

		xtx += x1*x1;
		xty += x1*y1;
	}

    

	this->printRegr();
}
void executor::quadraticRA(std::vector<float >x, std::vector<float > y)
{
	this->b0 = -0.25;
	this->b1 = 0.75;
	this->b2 = -0.03;

	this->printRegr();
}
void executor::printRegr()
{
	switch (this->tag)
	{
	case 0:
		
		std::cout << "y = " <<this->b0<< std::endl;
		break;
	case 1:
		std::cout << "y = " << this->b0 <<" + "<< this->b1 << " * x " << std::endl;
		break;
	case 2:
		std::cout << "y = " << this->b0 << " + (" << this->b1 << ") * x  + (" << this->b2 <<") * x^2 "<< std::endl;
		break;
	default:
		std::cout << "the regression model is not defined" << std::endl;
	}
}



