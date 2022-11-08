#pragma once
#include "Bindable.h"
class PixelShader :
    public Bindable
{
    wrl::ComPtr<ID3D11PixelShader>pPixelShader;
    wrl::ComPtr<ID3D10Blob>pBlob;
    std::wstring ShaderName;
  

public:PixelShader(Graphics& Gfx, std::wstring&& Filename);
        void Bind(Graphics& Gfx);

};

