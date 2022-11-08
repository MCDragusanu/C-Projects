float4 main(float4 color: COLOR) : SV_TARGET
{
	return float4(color.r,color.g,color.b,0.0f);
}