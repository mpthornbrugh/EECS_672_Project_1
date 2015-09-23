#version 410 core

in vec3 colorToFS;
uniform int primitiveColor;

// Replace the placeholder implementation here...

out vec4 fragmentColor;

void main()
{
	if (primitiveColor == 0) { //Grid
		fragmentColor = vec4(1.0, 1.0, 1.0, 1.0);
	}
	else if (primitiveColor == 1) { //Line 1
		fragmentColor = vec4(0.0, 0.0, 1.0, 1.0);
	}
	else if (primitiveColor == 2) { //Line 2
		fragmentColor = vec4(1.0, 0.0, 0.0, 1.0);
	}
	else if (primitiveColor == 3) { //Line 3
		fragmentColor = vec4(0.0, 1.0, 0.0, 1.0);
	}
	else { //Line 4
		fragmentColor = vec4(1.0, 0.0, 1.0, 1.0);
	}
}

