#include <iostream>
#include<iomanip>

using namespace std;

double Derivs(double t, double p){
	double k = 0.026;
	double pmax = 12000000000;
	return k*(1 - p / pmax)*p;
}

void RK4(double &x, double &y, double &h, double &ynew){
	double k1 = Derivs(x, y);
	double ym = y + k1*h / 2;
	double k2 = Derivs(x + h / 2, ym);
	ym = y + k2 *h / 2;
	double k3 = Derivs(x + h / 2, ym);
	double ye = y + k3 * h;
	double k4 = Derivs(x + h, ye);
	double slope = (k1 + 2 * (k2 + k3) + k4) / 6;
	ynew = y + slope*h;
	x = x + h;
}

void Integrator(double &x, double &y, double &h, double &xend){
	double ynew;
	//do
	if (xend - x < h){
		h = xend - x;
	}
	RK4(x, y, h, ynew);
	y = ynew;
	while (x < xend){
		if (xend - x < h){
			h = xend - x;
		}
		RK4(x, y, h, ynew);
		y = ynew;
	}
}

int main(){
	const int size = 100;
	double xp[size], yp[size];
	double y, xi, xf, dx, xout;
	cout << "Enter the initial value dependent variable:";
	cin >> y;
	cout << "Enter the initial value independent variable:";
	cin >> xi;
	cout << "Enter the final value independent variable:";
	cin >> xf;
	cout << "Enter the calculation step size:";
	cin >> dx;
	cout << "Enter the output interval:";
	cin >> xout;

	double x = xi;
	int m = 0;
	xp[m] = x;
	yp[m] = y;
	//do
	double xend = x + xout;
	if (xend > xf){
		xend = xf;
	}
	double h = dx;
	Integrator(x, y, h, xend);
	m = m + 1;
	xp[m] = x;
	yp[m] = y;
	while (x < xf){
		xend = x + xout;
		if (xend > xf){
			xend = xf;
		}
		h = dx;
		Integrator(x, y, h, xend);
		m = m + 1;
		xp[m] = x;
		yp[m] = y;
	}
	cout << setw(10) << "xp" << setw(10) << "yp" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << setw(10) << xp[i] << setw(10) << yp[i] << endl;
	}

	return 0;

}

//add coment