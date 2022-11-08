#pragma once
#include "Bindable.h"
struct Vertex
{
    float x, y, z, r, g, b, a;
};

class VertexBuffer :
    public Bindable
{
    wrl::ComPtr<ID3D11Buffer>pBuffer;
    static constexpr Vertex vertices[5]=
    {
        {0.0f, 0.5f, 0.33f, 0.22f, 0.22f},
        {0.5f,-0.5f, 0.66f, 0.21f, 0.05f},
        {-0.5f, -0.5f, 0.93f, 0.98f, 0.11f},
        {-0.15f, -0.95f, 0.93f, 0.98f, 0.11f},
        {0.08f, 0.85f, 0.33f, 0.22f, 0.22f},
    };
    D3D11_BUFFER_DESC bd;
    D3D11_SUBRESOURCE_DATA sd;
   
public:VertexBuffer(D3D11_BUFFER_DESC bd, D3D11_SUBRESOURCE_DATA sd, Graphics& Gfx);
        VertexBuffer(Graphics& Gfx);
        void Bind( Graphics& Gfx)override;
        void AddData(Vertex vertices[]);
        void Draw(Graphics& Gfx);
};

