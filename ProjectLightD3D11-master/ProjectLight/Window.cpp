#include "Window.h"
#include "Keyboard_and_Mouse.cpp"
#include "ExceptionHandler.cpp"
HWND Window::hWnd = nullptr;
LRESULT Window::result = 0;
LRESULT CALLBACK Window::Window_Proc(HWND h, UINT m, WPARAM w, LPARAM l)
{

    switch (m)
    {
    case WM_CLOSE:
    case WM_DESTROY:PostQuitMessage(0); break;

    default:result = DefWindowProc(h, m, w, l); break;
    }
    return result;
}

void Window::ProcessInput(const MSG& msg)
{

    switch (msg.message)
    {
    case WM_LBUTTONDOWN:mouse.LMButtonIsPressed(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_LBUTTONUP:mouse.LMButtonIsReleased(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_MOUSELEAVE:mouse.MouseLeave(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_MOUSEMOVE:mouse.MouseMove(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_MOUSEHWHEEL:mouse.MWheelMove(GET_WHEEL_DELTA_WPARAM(msg.wParam), GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_RBUTTONDOWN:mouse.RMButtonIsPressed(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_RBUTTONUP:mouse.RMButtonIsReleased(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_LBUTTONDBLCLK:mouse.LMButtonDBclick(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_RBUTTONDBLCLK:mouse.RMButtonDBClick(GET_X_LPARAM(msg.lParam), GET_Y_LPARAM(msg.lParam)); break;
    case WM_CHAR:
    case WM_KEYDOWN: { if (!(msg.lParam & 0x40000000) || false)
    {
        Keyb.SysKeyDown(msg.wParam);
        Keyb.SetKey(static_cast<char>(msg.wParam));
        Keyb.keydown = true;
        if (msg.wParam == VK_BACK)
        {
            Keyb.Delete = true;
        }
        if (msg.wParam == VK_SPACE)
        {
            Keyb.space = true;
        }
    }
    }break;

    case WM_KEYUP:Keyb.SysKeyUp(msg.wParam); break;
    }

}

Window::Window(int Width, int Height, std::string&& Title) :Class({ 0 }), msg({ 0 }), rc({ 0,0,1920,1080 })
{
    Class.cbSize = sizeof(WNDCLASSEX);
    Class.lpfnWndProc = Window_Proc;
    Class.hInstance = GetModuleHandle(nullptr);
    Class.hCursor = LoadCursor(NULL, IDC_ARROW);
    Class.lpszClassName = "ProjectRex";
    Class.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
    Class.hbrBackground = (HBRUSH)COLOR_WINDOW;
    
    
    
    if (!RegisterClassEx(&Class))
    {
        CreateMessageBox("Failed to Register the Class", "Error", MB_OK);
        CloseWindow(hWnd);
        PostQuitMessage(0);
    }
    else
    {
        hWnd = CreateWindowEx(WS_EX_ACCEPTFILES, Class.lpszClassName, Title.data(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Width, Height, NULL, NULL, Class.hInstance, NULL);
        AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
        ShowWindow(hWnd, SW_MAXIMIZE);
        SetFocus(hWnd);

    }
}

Window::~Window()noexcept
{
    UnregisterClass(Class.lpszClassName, Class.hInstance);

}

Window::Window(Window&& Other) noexcept :Class(std::move(Other.Class)), mouse(std::move(Other.mouse)), Keyb(std::move(Other.Keyb)), msg(std::move(Other.msg)), rc(std::move(Other.rc))
{

    Other.Class = { 0 };
    Other.hWnd = nullptr;
    Other.msg = { 0 };
    Other.result = 0;
}

bool Window::ProcessMessage()
{

    while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        ProcessInput(msg);
        if (msg.message == WM_QUIT)return false;

    }
    return true;
}

int Window::CreateMessageBox(const char* Text, const char* Title, UINT Button)
{
    return MessageBox(hWnd, Text, Title, Button);

}

Window::Exception::Exception(int line, const char* file, HRESULT hr) noexcept:
    __Exception(line,file),
     hr(hr)
{
}

const char* Window::Exception::what() const noexcept
{
    std::ostringstream oss;
   
    oss << GetType() << std::endl
        << "[Error Code]" << GetErrorCode() << std::endl
        << "[Desciption]" << GetErrorString() << std::endl
        << GetOriginString();
    whatBuffer = oss.str();
    return whatBuffer.c_str();
}

const char* Window::Exception::GetType() const noexcept
{
    return "Window Exception";
}

std::string Window::Exception::TranslateErrorCode(HRESULT hr) noexcept
{
    char* pMsgBuf = nullptr;
    DWORD nMSgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, hr,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPSTR>(&pMsgBuf), 0, nullptr);
    if (nMSgLen == 0)
    {
        return "Undefined error code";
    }
    std::string error_string= pMsgBuf;
    LocalFree(pMsgBuf);
    return error_string;
}

HRESULT Window::Exception::GetErrorCode() const noexcept
{
    return hr;
}

std::string Window::Exception::GetErrorString() const noexcept
{
   return TranslateErrorCode(hr);
}
