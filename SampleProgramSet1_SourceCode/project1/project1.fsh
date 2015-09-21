#version 410 core

in vec3 colorToFS;
uniform float primitiveColor;

// Replace the placeholder implementation here...

out vec4 fragmentColor;

void main()
{
	fragmentColor = vec4(primitiveColor,primitiveColor,primitiveColor,1.0);
}

