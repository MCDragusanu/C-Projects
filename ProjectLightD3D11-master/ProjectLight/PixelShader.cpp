#include "PixelShader.h"

PixelShader::PixelShader(Graphics& Gfx, std::wstring&& Filename):ShaderName(std::move(Filename))
{
	D3DReadFileToBlob(ShaderName.data(), &pBlob);
	Bindable::GetDevice(Gfx)->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader);
	
}

void PixelShader::Bind(Graphics& Gfx)
{
	Bindable::GetContext(Gfx)->PSSetShader(pPixelShader.Get(), 0, 0);
	
}
