#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef double real;
typedef double vect;
typedef double mat;

double w = 0;

vect* f, *x, *x_k, *x_x;
mat** matrix;
int N, m, max_iter = 100000;
real eps = 0.1e-13, norma_f = 0, EPS;