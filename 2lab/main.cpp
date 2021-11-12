#include <iostream>
#include <fstream>
#include "Header.h"


int main(int argc, char* argv[])
{
	ifstream in = ifstream("input.txt");
	ofstream out = ofstream("output.txt");

	lab2 lab;
	// считывание файлa
	lab.input(in);

	cout << "1-Jacobi" << endl << "2-Zeidel" << endl;
	int a = 0;
	cin >> a;
	switch (a) {
	case 1:
	{
		cout << "enter w:" << endl;
		cin >> lab.w;
		lab.Jacobi();
		lab.fout(out);
		break;
	}
	case 2:
	{
		cout << "enter w:" << endl;
		cin >> lab.w;
		lab.Zeidel();
		lab.fout(out);
		break;
	}
	{
	default:
		break;
	}
	}
	return 0;
}