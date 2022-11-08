#pragma once
#include "MainWindow.h"
#include <wrl/client.h>
class Graphics
{
	Microsoft::WRL::ComPtr<ID2D1Factory> pFactory;
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> RenderTarget;
	ID2D1SolidColorBrush* brush;
	HRESULT Res;
	D2D1_MATRIX_3X2_F RenderMatrix;
	double scale = 1.0f;
	float angle=0.0f;
	float dx = 0;
	float dy = 0;
	D2D_SIZE_F ScreenDimensions = { 1920,1080 };
public: Graphics(const HWND& hWnd);
	   ~Graphics();
	   void BeginDraw() { RenderTarget->BeginDraw();}
	   void EndDraw() { RenderTarget->EndDraw();}
	   void SetBackground(unsigned int color) { RenderTarget->Clear(D2D1::ColorF(color));}
	   void DrawEllipse(D2D1_ELLIPSE, unsigned int);
	   template<class Point>
	   void DrawLine(Point Point1, Point Point2)
	   {

		   RenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::LawnGreen), &brush);
		   RenderTarget->DrawLine(Point1, Point2, brush, 2.0f);
	   }
	   template<class Point>
	   void DrawLine(Point Point2)
	   {

		   RenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::LawnGreen), &brush);
		   RenderTarget->DrawLine({ 0,0 }, Point2, brush, 2.0f);
	   }
	   void DrawRect(D2D1_RECT_F rc);
	   void TrasformPerspective(Mouse mouse,Keyboard kbd);
	   
};