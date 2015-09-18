#version 410 core

in vec3 colorToFS;

// Replace the placeholder implementation here...

out vec4 fragmentColor;

void main()
{
	fragmentColor = vec4(colorToFS,1.0);
}

