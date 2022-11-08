#include "Graphics.h"



Graphics::Graphics(const HWND& hWnd)
{

	RenderTarget = nullptr;
	brush = NULL;
	
	RECT rc;
	GetClientRect(hWnd, &rc);
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	Res = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, pFactory.GetAddressOf());
	Res = pFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), 
		                                  D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rc.right, rc.bottom)), 
		                                  RenderTarget.GetAddressOf());
	
}
Graphics::~Graphics()
{
	
	
}
void Graphics::DrawEllipse(D2D1_ELLIPSE Ellipse, unsigned int color)
{
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(color), &brush);
	RenderTarget->DrawEllipse(Ellipse, brush);
	RenderTarget->FillEllipse(Ellipse, brush);
	brush->Release();
}

void Graphics::DrawRect(D2D1_RECT_F rc)
{
	ID2D1SolidColorBrush* Brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DarkRed), &Brush);
	RenderTarget->DrawRectangle(rc, Brush);
	RenderTarget->FillRectangle(rc, Brush);
}
void Graphics::TrasformPerspective(Mouse mouse, Keyboard kbd)
{
	if (kbd.GetKeyState().ArrowUp)
	{
		dy -= 50;
		
	}
	if (kbd.GetKeyState().ArrowDown)
	{
		dy += 50;
		
	}
	if (kbd.GetKeyState().ArrowRight)
	{
		dx -= 50;
		
	}
	if (kbd.GetKeyState().ArrowLeft)
	{
		dx += 50;
	}
	if (kbd.GetKeyState().Plus)
	{
		MessageBeep(MB_OK);
		
		scale += 0.1;
	}
	if (kbd.GetKeyState().Minus)
	{
		MessageBeep(MB_OK);

		scale -= 0.1;
	}
	if (mouse.GetMouseState().DbClick)
	{
		this->scale = 1.0f;
		mouse.OnLMbuttonDbclickEnd();
	}
	D2D1_MATRIX_3X2_F Translate = D2D1::Matrix3x2F::Translation(dx, dy);
	D2D1_MATRIX_3X2_F Scale = D2D1::Matrix3x2F::Scale(scale, scale, {960,540});
	
	RenderTarget->SetTransform(Translate*Scale);
	
	
}
