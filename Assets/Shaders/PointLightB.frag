uniform float ScreenWidth; 
uniform float ScreenHeight; 
uniform vec2 position; 
uniform float radius; 
uniform vec3 color; 
uniform float intensity; 
void main() 
{ 
	vec2 pixelPos = gl_TexCoord[0].st * vec2(ScreenWidth, ScreenHeight).xy; 
	float dist = distance(position, pixelPos); 
	float distanceFactor = (radius - dist) / radius; 
	vec4 outputcolor = vec4(0, 0, 0, 1); 
	if (distanceFactor >= 0) { 
		outputcolor.xyz = clamp((distanceFactor)*intensity, 0.0, 1.0)*color; 
	}else { 
		outputcolor = vec4(0, 0, 0, 0); 
	} 
	gl_FragColor = outputcolor; 
};