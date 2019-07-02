#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "IObserver.h"
class executor : 	public IObserver
{
	// name of executor
	std::string name;
	int tag;
	float c;

public:
	executor(int _tag, std::string _name) : tag(_tag), name(_name) {};

	void Update(int tag, std::vector<float>x, std::vector <float> y)
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
protected:
	float b0, b1, b2;
	void constRA(std::vector<float > y);
	void linearRA(std::vector<float >x, std::vector<float > y);
	void quadraticRA(std::vector<float >x, std::vector<float > y);
	void printRegr();
private:
	typedef std::vector<double> Vec;
	typedef std::vector<Vec> Mat;

	Vec dotXy  (const Mat &a, const Vec &x){
		int i, j;
		int m = a.size();
		int n = x.size();

		Vec prod(m);

		for (i = 0; i < m; i++){
			prod[i] = 0.;
			for (j = 0; j < n; j++)
				prod[i] += a[i][j] * x[j];
		}
		return prod;
	}
	Mat dotXX(const Mat &x){
		int i, j,k;
		int m = x.size();
		int n = x[0].size();

		Mat prod(m);

		for (i = 0; i < m; i++){
			prod[i][j] = 0.;
			for (k = 0; k < n; k++)
				prod[i][j] += x[k][j] * x[k][j];
		}
		return prod;
	}
};



