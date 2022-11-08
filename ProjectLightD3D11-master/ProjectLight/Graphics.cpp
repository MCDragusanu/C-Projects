#include "Graphics.h"
#include "VertexBuffer.cpp"
#include "InputLayout.cpp"
#include "PixelShader.cpp"
#include "VertexShader.cpp"

Graphics::Graphics(const HWND& handle)
{
	DXGI_SWAP_CHAIN_DESC sd = {0};
	
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = handle;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;
		D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			nullptr,
			0,
			D3D11_SDK_VERSION,
	       &sd,
			&pSwapChain,
			&pDevice,
			nullptr,
			&pContext
			);
		pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(pBackBuffer.ReleaseAndGetAddressOf()));
		pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &pTarget);
		
}

void Graphics::EndFrame()
{
	pSwapChain->Present(1u, 0u);
}

void Graphics::ClearBuffer(float r, float g, float b) noexcept
{
	const float color[] = { r,g,b,1.0 };
	pContext->ClearRenderTargetView(pTarget.Get(), color);
}

void Graphics::DrawCall()
{
	
		 

		 VertexBuffer vBuffer(*this);
		 vBuffer.Bind(*this);
	

	//crearea si adaugarea pixel shaderului
	
		 PixelShader PixelShader(*this, L"PixelShader.cso");
		 PixelShader.Bind(*this);

	//crearea si adaugarea VertexShader


	VertexShader VertexShader(*this, L"VertexShader.cso");
	VertexShader.Bind(*this);

	//crearea inputului de vertexuri	
	//are nevoie de rezultatul vertex shaderului pentru a calcula punctele;
	//e nevoie de cate un input layout pt fiecare shader
	//
	
	
	//wrl::ComPtr<ID3D11InputLayout>pInputLayout;
	//const D3D11_INPUT_ELEMENT_DESC ied[] = {
	//	{"Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
	//	{"Color",0,DXGI_FORMAT_R8G8B8A8_UNORM,0,2 * sizeof(float),D3D11_INPUT_PER_VERTEX_DATA,0},
	//};
	//pDevice->CreateInputLayout(ied, (UINT)std::size(ied), pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &pInputLayout);
	////adaugarea Input layoutului
	//pContext->IASetInputLayout(pInputLayout.Get());
	////adaugarea RenderTargetului
	//pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

	//descrierea ecranului
	D3D11_VIEWPORT vp;
	vp.Width = 1920;
	vp.Height = 1080;
	vp.MinDepth = 0;
	vp.MaxDepth = 1;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	//Vertexurile sunt puse sa fie unite intr-o aumita ordine
	pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//adaugarea viewportului in pipeline
	pContext->RSSetViewports(1u, &vp);

	vBuffer.Draw(*this);
	//pContext->Draw((UINT)std::size(vertices), 0);
	
}


