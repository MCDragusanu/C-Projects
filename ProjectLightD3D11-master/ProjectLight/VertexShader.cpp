#include "VertexShader.h"

VertexShader::VertexShader(Graphics& Gfx, std::wstring&& Filename):ShaderName(std::move(Filename))
{
	D3DReadFileToBlob(ShaderName.c_str(), &pBlob);
	Bindable::GetDevice(Gfx)->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader);
	pInputLayout = std::make_unique<InputLayout>(Gfx, pBlob.Get());
}


void VertexShader::Bind(Graphics& Gfx)
{
	Bindable::GetContext(Gfx)->VSSetShader(pVertexShader.Get(), 0, 0);
	
	pInputLayout->Bind(Gfx);
}
