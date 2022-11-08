#pragma once
#include "Bindable.h"
class VertexShader :
    public Bindable
{
    wrl::ComPtr<ID3D11VertexShader>pVertexShader;
    wrl::ComPtr<ID3D10Blob>pBlob;
    std::wstring ShaderName;
    std::unique_ptr<InputLayout> pInputLayout;
public:VertexShader(Graphics& Gfx, std::wstring&& Filename);
      void Bind(Graphics& Gfx);
};

