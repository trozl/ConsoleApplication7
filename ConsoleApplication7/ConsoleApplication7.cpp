#include<iostream>
#include<locale>
#include<cmath>

#define eps 0.001
#define x1 0.1;
#define x2 0.77;
#define x3 -0.9;
using namespace std;

int main() {
	int switchstate;
	double x,  delt, lasto, otv,xstep ;
	setlocale(LC_ALL, "RUS");
	printf("Выберете x из списка:\n1. %lf\n2. %lf\n3. %lf\n", 0.1, 0.77,  (- 0.9));
	cin >> switchstate;
	while (switchstate > 3 || switchstate < 1) {
		printf("Выбранно неверное значение x, введите значение повторно\n");
		cin >> switchstate;
	}
	switch (switchstate) {
	case 1: x = 0.1;
		break;
	case 2: x = 0.77;
		break;
	case 3: x = -0.9;
		break;
	}
	delt = 1;
	otv = 0;
	for (int i = 1; delt > eps; i++) {
		if (i > 1) {
			xstep = x * x;
		}
		if (i % 2 != 0) {
			if (i == 1) {
				otv = otv + i;
			}
			if (i != 1) {
				otv = otv + i * xstep;

			}
		}
			if (i % 2 == 0) { 
			otv = otv - i * xstep;
		}
		if (i >= 2) { 
			delt = otv - lasto;
		}
		lasto = otv;
	}
	printf("Ответом выражения при x = %f будет %lf", x, otv);

}