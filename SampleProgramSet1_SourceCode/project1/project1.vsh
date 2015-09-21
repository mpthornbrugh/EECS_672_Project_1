#version 410 core

in vec2 mcPosition;

uniform vec4 scaleTrans;

// replace the placeholder implementation here

void main()
{
	float ldsX = scaleTrans[0]*mcPosition.x + scaleTrans[1];
	float ldsY = scaleTrans[2]*mcPosition.y + scaleTrans[3];
	gl_Position = vec4(ldsX, ldsY, 0, 1);
}

