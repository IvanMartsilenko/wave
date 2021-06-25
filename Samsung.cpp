// Samsung.cpp : Defines the entry point for the application.
// Created by Ivan Martsilenko

#include <windows.h>
#include <gdiplus.h>
#include "BMP.h" 

#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;

#include <time.h>  // need for program work time measurement 
#include <fstream> // 



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	BMP canonic = BMP("this_is_fine.bmp");
	int alpha = 45;
	double n = 30.0; // amplitude
	double v = 40;  // speed
	double l = 200; // wave length ( distortion zone width)

	Waves wave = Waves(canonic.bmp_info_header.height, canonic.bmp_info_header.width, alpha, n, v, l);



	clock_t start = clock();
	double seconds = -1;
	//initializating
	
	const char* filename = "wave.bmp";
	BMP bmp = BMP(canonic.bmp_info_header.width, canonic.bmp_info_header.height, canonic.bmp_info_header.bit_count == 32);
	canonic.write(filename);

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);



	const wchar_t CLASS_NAME[] = L"Waves Distortion";
	WNDCLASS wc = {};
	wc.lpfnWndProc = &WindowProc; //attach this callback procedure
	wc.hInstance = hInstance; //handle to application instance
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc); //register wc
	

	// Create the window.
	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"Waves Distortion",			// Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, bmp.bmp_info_header.width, bmp.bmp_info_header.height,

		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);


	MSG msg;
	if (hwnd != NULL)
	{

		ShowWindow(hwnd, nCmdShow);
		for (int t = 0; t < wave.get_t_end(); ++t)
		{

			bmp.process_rows(wave, t, canonic);
			bmp.write(filename);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);

		}
		clock_t end = clock();
		seconds = (double)(end - start) ;
		while (GetMessage(&msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	GdiplusShutdown(gdiplusToken);
	std::ofstream myfile;
	myfile.open("multithread.txt");
	myfile << "The time: " << seconds << " seconds * clocs_per_sec\n";
	myfile << "Image: sample_1.bmp\n";
	myfile << "Wave settings: \n";
	myfile << "\n\talpha: " << wave.get_alpha();
	myfile << "\n\tV: " << wave.get_V() ;
	myfile << "\n\tT: " << wave.get_T() ;
	myfile << "\n\tamplitude(n): " << wave.get_amplitude();
	myfile << "\n\tlength: " << wave.get_lambda() ;
	myfile << "\n\tX_start: " << wave.get_X_start();
	myfile << "\n\tY_start: " << wave.get_Y_start();


	myfile.close();
	return 0;
}
void Example_DrawImage9(HDC hdc)
{
	Graphics graphics(hdc);
	// Create an Image object.
	Image image(L"wave.bmp");

	// Draw the original source image.
	graphics.DrawImage(&image, 0, 0);
}

//callback procedure for this window, takes in all the window details
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);;
		Example_DrawImage9(hdc);
		EndPaint(hwnd, &ps);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

