#pragma once
#include "Keyboard_and_Mouse.h"
#include "ExceptionHandler.h"
class Window
{
	static HWND hWnd;
	static LRESULT CALLBACK Window_Proc(HWND, UINT, WPARAM, LPARAM);
	static LRESULT result;
	WNDCLASSEX Class;
	void ProcessInput(const MSG&);
	RECT rc;
	MSG msg;
public:Window(int Width, int Height, std::string&& Title);
	  ~Window()noexcept;
	  Window(const Window&) = delete;
	  Window(Window&&)noexcept;
	  bool ProcessMessage();
	  int CreateMessageBox(const char* Text, const char* Title, UINT Button);
	  HWND GetHandle()const { return hWnd; }
	  Keyboard Keyb;
	  Mouse mouse;
	  class Exception :public __Exception
	  {
	  public:Exception(int line, const char* file,HRESULT hr)noexcept;
			const char* what()const noexcept override;
			virtual const char* GetType()const noexcept;
			static std::string TranslateErrorCode(HRESULT hr)noexcept;
			HRESULT GetErrorCode()const noexcept;
			std::string GetErrorString()const noexcept;
	  private:HRESULT hr;
	  };
};
#define HWND_EXEPT(hr) Window::Exception(__LINE,__FILE,hr)