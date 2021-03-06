// project1.c++

#include <iostream>
#include <fstream>
#include <queue>
#include "GLFWController.h"
#include "ModelView.h"

void makeGrid(Controller& c, int maxWidth) {
	vec2 vertexPositions[] =
	{
		{0.0,0.0},{maxWidth,0.0},
		{0.0,0.0},{0,1.6},
		{0.0,0.2},{maxWidth,0.2},
		{0.0,0.4},{maxWidth,0.4},
		{0.0,0.6},{maxWidth,0.6},
		{0.0,0.8},{maxWidth,0.8},
		{0.0,1.0},{maxWidth,1.0},
		{0.0,1.2},{maxWidth,1.2},
		{0.0,1.4},{maxWidth,1.4},
		{0.0,1.6},{maxWidth,1.6}
	};

	c.addModel( new ModelView(vertexPositions, 0, 20, 1) );
}

int main(int argc, char* argv[])
{
	GLFWController c(argv[0]);
	c.reportVersions(std::cout);

	std::ifstream is("ExchangeRates.csv");

	std::string date;
	float rate1, rate2, rate3, rate4;
	char comma;
	int nLines = 0;
	vec2 vertexPositions1[121];
	vec2 vertexPositions2[121];
	vec2 vertexPositions3[121];
	vec2 vertexPositions4[121];
	while (is >> date >> rate1 >> comma >> rate2 >> comma >> rate3 >> comma >> rate4)
	{
		vertexPositions1[nLines][0] = nLines * 1.0;
		vertexPositions1[nLines][1] = rate1;
		vertexPositions2[nLines][0] = nLines * 1.0;
		vertexPositions2[nLines][1] = rate2;
		vertexPositions3[nLines][0] = nLines * 1.0;
		vertexPositions3[nLines][1] = rate3;
		vertexPositions4[nLines][0] = nLines * 1.0;
		vertexPositions4[nLines][1] = rate4;
		++nLines;
	}
	
	makeGrid(c, nLines);
	c.addModel( new ModelView(vertexPositions1, 1, nLines, 0) );
	c.addModel( new ModelView(vertexPositions2, 2, nLines, 0) );
	c.addModel( new ModelView(vertexPositions3, 3, nLines, 0) );
	c.addModel( new ModelView(vertexPositions4, 4, nLines, 0) );

	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);

	// This is done so that the grid is shown with a border around it.
	xyz[0] -= 5;
 	xyz[1] += 5;
 	xyz[2] -= .1;
 	xyz[3] += .1;

	// Simplest case: Just tell the ModelView we want to see it all:
	ModelView::setMCRegionOfInterest(xyz);

	c.run();

	return 0;
}
