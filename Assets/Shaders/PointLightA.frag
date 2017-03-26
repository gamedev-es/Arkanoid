uniform float ScreenWidth;
uniform float ScreenHeight;
uniform vec2 position;
uniform vec3 color;
uniform float intensity;
uniform float radius;
void main()
{
	vec2 pixelPos = gl_TexCoord[0].st * vec2(ScreenWidth, ScreenHeight);
	float dist = distance(position, pixelPos);
	
	float  att = 1 - pow( clamp( dist/radius, 0.0, 1.0 ), intensity );
	gl_FragColor.xyz = clamp(att * color, 0.0, 1.0);
}