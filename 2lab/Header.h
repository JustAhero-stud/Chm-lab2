#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


typedef double real;
typedef double vect;
typedef double mat;


class lab2 {
   double w = 0;

   vect *f, *x, *x_k, *x_x;
   mat** matrix;
   int N, m, max_iter = 100000;
   real eps = 0.1e-13, norma_f = 0, EPS;

   void input(ifstream& in);
   double Iteration(vect* x_k, vect* x_x);
   void fout(int iter, real eps_);
   void Jacobi(vect* x_k, vect* x_x);
   void Zeidel(vect* x_x);
  
};
