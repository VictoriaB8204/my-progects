// Shape.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

const double pi = 3.14;

class Shape{
public:
	Shape();
	virtual double getSquare() = 0;
};

class Rectangle: public Shape{
	double a_;
	double b_;
public:
	Rectangle(double a, double b){
		a_ = a;
		b_ = b;
	};
	double getSquare(){
		return a_*b_;
	};
};

class Circle: public Shape{
	double r_;
public:
	double getSquare(){
		return pi*r_*r_;
	};
};

class Square: public Shape{
	double a_;
public:
	double getSquare(){
		return a_*a_;
	};
};

//vector<Shape>::push_back(Rectangle* rectangle){};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Shape> v;
	v.push_back(2,3);
	system("pause");
	return 0;
}

