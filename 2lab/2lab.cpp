#include "Matrix.h"


void lab2:: input(ifstream& in)
{
	ifstream in("input.txt");
	// считывание размерности матрицы
	in >> N;
	x_k = new vect[N];
	x_x = new vect[N];
	for (int i = 0; i < N; i++)
	{
		x_x[i] = 0;
	}
	for (int i = 0; i < N; i++)
	norma_f += f[i] * f[i];
	norma_f = sqrt(norma_f);

	cout << "Size: " << N << endl;
	// считывание кол-ва стобцов между диаг
	in >> m;
	cout << "m: " << m << endl;
	
	// выделение памяти под двумерный массив
	// N строчек и 7 столбцов тк 7 диагональная по заданию
	matrix = new mat * [N];
	for (int i = 0; i < N; i++)
		matrix[i][7];
	// считывание матрицы в двумерный вектор
	cout << endl << "Our matrix:\n";
	for (int i = 0; i < N; i++, cout << endl)
	{
		for (int j = 0; j < 7; j++)
		{
			in >> matrix[i][j];
			cout.width(2);
			cout << matrix[i][j] << " ";
		}
	}
	// считывание вектора f
	f = new vect[N];
	cout << endl << "F vector: ";
	for (int i = 0; i < N; i++)
	{
		in >> f[i];
		cout << f[i] << " ";
	}
	cout << endl;
	// считывание вектора начального приближения
	x = new vect[N];
	cout << "X vector: ";
	for (int i = 0; i < N; i++)
	{
		in >> x[i];
		cout << x[i] << " ";
	}
	cout << endl;
	in.close();
}

double Iteration(vect* x_k, vect* x_x)
{
	int k_1 = 0, k_2 = 0, jj = 0;
	real sum = 0, nevyazka = 0, sum_nev = 0, nev = 0;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || j == 1)
				k_1 = 1;
			else
				k_1 = 0;
			if (j == 5 || j == 6)
				k_2 = 1;
			else
				k_2 = 0;
			jj = i + j - 3 - m * k_1 + m * k_2;
			if (jj >= 0 && jj < N)
				sum += matrix[i][j] * x_k[jj];
		}
		nev = f[i] - sum;
		x_x[i] = x_k[i] + w * nev / matrix[i][3];
		sum_nev += nev * nev;
	}
	sum_nev = sqrt(sum_nev);
	return sum_nev;
}

void lab2:: output(ofstream& out)
{
	ofstream out("output.txt");
	out << "epsilon " << eps_ << endl;
	out << fixed;
	out.precision(15);
	for (int i = 0; i < N; i++)
	{
		out.width(2);
		out << i + 1 << " ";
		out << "| " << "x = " << x_k[i];
		out << " | " << "x* - x = " << i + 1.0 - x_k[i] << " ";
		out << endl;
	}
	out << "iter: " << iter - 1 << "\t\teps_: ";
	if (iter > max_iter)
		out << "Exceeded the number of iterations" << endl;
	else
		out << "The specified approximation has been achieved" << endl;
	real norma_1 = 0;
	real norma_2 = 0;
	real mA = 0;
	for (int i = 0; i < N; i++)
	{
		norma_1 += (x_k[i] - (i + 1.0)) * (x_k[i] - (i + 1.0));
		norma_2 += (i + 1.0) * (i + 1.0);
	}
	norma_1 = sqrt(norma_1);
	norma_2 = sqrt(norma_2);
	mA = (norma_1 / norma_2) / EPS;
	out << "mA >= " << mA << endl;

}

void lab2:: Jacobi()
{
	for (int i = 0; i < N; i++)
		x_k[i] = x[i];
	for (iter = 0; iter <= max_iter && eps_ >= eps; iter++)
	{
		nevyazka = Iteration(x_k, x_x);
		eps_ = nevyazka / norma_f;
		for (int i = 0; i < N; i++)
			x_k[i] = x_x[i];
	}
	EPS = eps_;
}
void lab2:: Zeidel()
{
	for (int i = 0; i < N; i++)
		x_x[i] = x[i];
	for (iter = 0; iter <= max_iter && eps_ >= eps; iter++)
	{
		nevyazka = Iteration(x_x, x_x);
		eps_ = nevyazka / norma_f;
		for (int i = 0; i < N; i++)
			x_k[i] = x_x[i];
	}
	EPS = eps_;
}
