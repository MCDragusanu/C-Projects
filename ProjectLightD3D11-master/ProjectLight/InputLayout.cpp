#include "InputLayout.h"

InputLayout::InputLayout(Graphics& gfx, ID3D10Blob* pBlob)
{
	DescriptorList.push_back({ "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 });
	DescriptorList.push_back({ "Color",0,DXGI_FORMAT_R8G8B8A8_UNORM,0,2 * sizeof(float),D3D11_INPUT_PER_VERTEX_DATA,0 });
	
	const D3D11_INPUT_ELEMENT_DESC ied[] = {
		{"Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
		{"Color",0,DXGI_FORMAT_R8G8B8A8_UNORM,0,2 * sizeof(float),D3D11_INPUT_PER_VERTEX_DATA,0},
		};
	

	Bindable::GetDevice(gfx)->CreateInputLayout(ied, (UINT)std::size(ied), pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &pInputLayout);

}

InputLayout::InputLayout(Graphics& gfx, std::vector<D3D11_INPUT_ELEMENT_DESC>&& Input, ID3D10Blob* pBlob):DescriptorList(std::move(Input))
{

}

void InputLayout::Bind(Graphics& Gfx)
{
	Bindable::GetContext(Gfx)->IASetInputLayout(pInputLayout.Get());
}
