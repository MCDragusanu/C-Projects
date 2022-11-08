#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(D3D11_BUFFER_DESC bd, D3D11_SUBRESOURCE_DATA sd, Graphics& Gfx):bd(bd),sd(sd)
{
	Bindable::GetDevice(Gfx)->CreateBuffer(&bd, &sd, &pBuffer);
}

VertexBuffer::VertexBuffer(Graphics& Gfx):sd({}),bd({})
{
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(vertices);
	bd.StructureByteStride = sizeof(Vertex);
	 
	D3D11_SUBRESOURCE_DATA sd = {  };
	sd.pSysMem = vertices;
	
	Bindable::GetDevice(Gfx)->CreateBuffer(&bd, &sd, &pBuffer);
}




void VertexBuffer::Bind(Graphics& Gfx)
{
    const UINT stride = sizeof(Vertex);
	 const UINT offset = 0u;
	Bindable::GetContext(Gfx)->IASetVertexBuffers(0u, 1u, pBuffer.GetAddressOf(), &stride, &offset);
}




void VertexBuffer::AddData(Vertex vertices[])
{
	
	/*UINT nVertices = std::size(Vertices);
	for (UINT i = 0; i < nVertices; i++)
	{
		Vertices.emplace_back(vertices[i]);
	}*/
}

void VertexBuffer::Draw(Graphics& Gfx)
{
	Bindable::GetContext(Gfx)->Draw(std::size(vertices), 0);
}
