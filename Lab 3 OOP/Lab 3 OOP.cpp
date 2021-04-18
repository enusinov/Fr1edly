#include "base.h"
#include <iomanip>
#include <iostream>

using namespace Base;

int main()
{
	matrix a(5), b, c(5);
	vector d;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
		a[i][j] = rand()%50;
		c[i][j] = rand()%50;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(5) << a[i][j]<<"-" << c[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << d.GetType() << endl;
	 a+=c;
	cout << d.GetType() << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(5) << a[i][j] << "-" << c[i][j];
		}
		cout << endl;
	}
}
