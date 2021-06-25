#include "waves.h"
#include <stdlib.h>     /* rand */
#include <cmath> /* pow, sqrt,tan, abs*/


Pixels Waves::DefineStartPoints()
{
	Pixels StartPoint = Pixels(0, 0); // C (0;0)									//
	if (alpha < 90)																// A ________________________ B
	{																				//	|                        |
		StartPoint = Pixels(height, 0); // A(m:0))									//	|                        |
	}																				//	|                        |
	else if (alpha < 180)															//	|                        |
	{																				//	|                        |
		StartPoint = Pixels(height, width); // B (m;n)								//	|                        |
	}																				//C  ------------------------  D
	else if (alpha < 270)															//
	{
		StartPoint = Pixels(0, width); // D ( 0;n)
	}
	return StartPoint;
}

Pixels Waves::DefineEndPoints()
{
	Pixels 	EndPoint = Pixels(height, width); // B (m;n) 
	if (alpha < 90)
	{
		EndPoint = Pixels(0, width ); // D ( 0;n)
	}
	else if (alpha <180)
	{
		EndPoint = Pixels(0, 0); // C (0;0)
	}
	else if (alpha < 270)
	{
		EndPoint = Pixels(height, 0); // A(m:0))	
	}
	return EndPoint;
}


double Waves::CalculateTend(Pixels Start, Pixels End)
{
	double diag = sqrt(pow(Start.get_X() - End.get_X(), 2) + pow(Start.get_Y() - End.get_Y(),2));
	double distance = abs(b) + diag;
	double res = lambda/V;
	if (alpha == 270 || alpha == 90) res += T + height / V;
	else res += T + abs(distance / (V * cos(alpha * 3.14159265 / 180.0)));
	return res;
}

Waves::Waves(int h, int w)
{
	alpha = rand() % 360;
	height = h;
	width = w;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = (rand() % 200) / (20.0);
	amplitude = (rand() % 200) / (20.0);
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w,int a)
{
	height = h;
	width = w;
	alpha = a;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = (rand() % 200) / (20.0);
	amplitude = (rand() % 200) / (20.0);
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, int a, double n)
{
	height = h;
	width = w;
	alpha = a;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = (rand() % 200) / (20.0);
	amplitude = n;
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, int a, double n, double v)
{
	height = h;
	width = w;
	alpha = a;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = v;
	amplitude = n;
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, int a, double n, double v, double l)
{
	height = h;
	width = w;
	alpha = a;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = v;
	amplitude = n;
	lambda = l;
	T = lambda / v;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)* tan(alpha * 3.14159265 / 180.0);

	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, double n)
{
	height = h;
	width = w;
	alpha = rand() % 360;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = (rand() % 200) / (20.0);
	amplitude = n;
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, double n, double v)
{
	height = h;
	width = w;
	alpha = rand() % 360;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = v;
	amplitude = n;
	lambda = (rand() % 200) / (20.0);
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

Waves::Waves(int h, int w, double n, double v, double l)
{
	height = h;
	width = w;
	alpha = rand() % 360;
	X_start = DefineStartPoints().get_X();
	Y_start = DefineStartPoints().get_Y();
	V = v;
	amplitude = n;
	lambda = l;
	T = lambda / V;
	if (alpha == 90 || alpha == 360) b = 0;
	else if (alpha == 270 || alpha == 180) b = width;
	else b = Y_start - (X_start)*tan(alpha * 3.14159265 / 180.0);
	t_end = CalculateTend(DefineStartPoints(), DefineEndPoints());
}

int Waves::get_alpha()
{
	return alpha;
}

int Waves::get_X_start()
{
	return X_start;
}

int Waves::get_Y_start()
{
	return Y_start;
}

double Waves::get_V()
{
	return V;
}

double Waves::get_amplitude()
{
	return amplitude;
}

double Waves::get_lambda()
{
	return lambda;
}

double Waves::get_T()
{
	return T;
}

double Waves::get_t_end()
{
	return t_end;
}

double Waves::get_b()
{
	return b;
}