#pragma once
class Bindable
{
protected:
    static ID3D11Device* GetDevice(Graphics& gfx) { return gfx.pDevice.Get(); };
    static ID3D11DeviceContext* GetContext(Graphics& gfx) { return gfx.pContext.Get(); };


public:Bindable() {};
      virtual void Bind( Graphics& gxf  ) = 0;
     
};

