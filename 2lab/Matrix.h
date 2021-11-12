#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef double real;
typedef double vect;
typedef double mat;


class lab2
{
public:
	double w = 0;
	vect* f, * x, * x_k, * x_x;
	mat** matrix;
	int N;
	int m;
	int max_iter = 100000;
	int iter = 0;
	real eps = 0.1e-13;
	real norma_f = 0;
	real EPS;
	real sum_nev;
	real eps_ = 1;
	real nevyazka = 0;

	void input(ifstream& in);
	void Jacobi();
	void Zeidel();
	void output(ofstream& out)



};