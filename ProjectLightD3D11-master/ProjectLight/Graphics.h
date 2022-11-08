#pragma once
#include "PreCompiledHeaders.h"
#pragma comment(lib,"d3d11")
#pragma comment(lib,"D3DCompiler.lib")
namespace wrl = Microsoft::WRL;


class Graphics
{
	wrl::ComPtr<ID3D11Device>pDevice;
	wrl::ComPtr<IDXGISwapChain>pSwapChain;
	wrl::ComPtr<ID3D11DeviceContext>pContext;
	wrl::ComPtr<ID3D11Resource>pBackBuffer;
	wrl::ComPtr<ID3D11RenderTargetView>pTarget;

public:Graphics(const HWND& handle);
	  void EndFrame();
	  void ClearBuffer(float r, float g, float b) noexcept;
	  void DrawCall();
	 
	  friend class Bindable;
};
#include "Bindable.h"
#include "VertexBuffer.h"
#include "InputLayout.h"
#include "PixelShader.h"
#include "VertexShader.h"
