uniform sampler2D texture; 
uniform vec2 position; 
uniform vec3 color; 
uniform float bright; 
uniform float angle; 
uniform float angularAtenuation; 
void main() 
{ 
        float dist = distance(gl_FragCoord.xy,position); 
        gl_FragColor = texture2D(texture,gl_FragCoord.xy); 
        if(angularAtenuation <0.001) 
        { 
            gl_FragColor.xyz += (color*exp(-dist/50.0))+((1.0,1.0,1.0)*bright*exp(-dist/20.0));  
        } 
        else 
        { 
            float pixelAngle = atan((gl_FragCoord.xy-position).y,(gl_FragCoord.xy-position).x); 
            if(abs(pixelAngle-radians(angle))<radians(angularAtenuation)) 
            { 
                gl_FragColor.xyz += (color*exp(-dist/150.0)*exp(-abs(pixelAngle-radians(angle))))+((1.0,1.0,1.0)*bright*exp(-dist/20.0)); 
            } 
        } 
};
