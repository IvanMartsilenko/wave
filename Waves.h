#pragma once
#include "pixels.h"
#pragma pack(push, 1)
class Waves {
	private: 
		int alpha; // wave angle
		int X_start;
		int Y_start;
		double V;
		double amplitude; // Amplitude, n it's documantation naming of amplitude.
		double lambda; // wave length
		double T; // wave period
		double t_end; // time when wave left last pixel
		double b;
		Pixels DefineStartPoints();
		Pixels DefineEndPoints();

		double CalculateTend(Pixels Start, Pixels End);
		int height;
		int width;
	public:
		Waves(int h, int w);
		Waves(int h, int w,int a);
		Waves(int h, int w,int a, double n);
		Waves(int h, int w,int a, double n, double v);
		Waves(int h, int w,int a, double n, double v, double l);
		Waves(int h, int w,double n);
		Waves(int h, int w,double n, double v);
		Waves(int h, int w,double n, double v, double l);

		int get_alpha();
		int get_X_start();
		int get_Y_start();
		double get_V();
		double get_amplitude();
		double get_lambda();
		double get_T();
		double get_t_end();
		double get_b();// koef in wave formula  y = tan(alpha)*x + b

};