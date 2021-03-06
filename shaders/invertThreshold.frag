#version 150

uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{
    float c =texture(tex0, texCoordVarying).g + texture(tex0, texCoordVarying).r + texture(tex0, texCoordVarying).b;
    c /= 3;
    
    outputColor = c < 0.5 ? vec4(1,1,1,1):vec4(0,0,0,1);;
}