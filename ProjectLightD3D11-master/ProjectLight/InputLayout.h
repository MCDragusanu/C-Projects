#pragma once
#include "Bindable.h"
class InputLayout :
    public Bindable
{
    wrl::ComPtr<ID3D11InputLayout>pInputLayout;
   std::vector< D3D11_INPUT_ELEMENT_DESC>DescriptorList;
public:InputLayout(Graphics& gfx,ID3D10Blob* pBlob);
         InputLayout(Graphics& gfx, std::vector<D3D11_INPUT_ELEMENT_DESC>&& Input,ID3D10Blob* pBlob);
        void Bind(Graphics& Gfx);
};

