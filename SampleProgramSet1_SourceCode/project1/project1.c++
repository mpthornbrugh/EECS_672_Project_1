// project1.c++

#include <iostream>
#include <fstream>
#include "GLFWController.h"
#include "ModelView.h"

void makeGrid(Controller& c, int maxWidth) {
	vec3 vertexColors[20] = {
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5}
	};

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

	c.addModel( new ModelView(vertexPositions, vertexColors, 20) );
}

int main(int argc, char* argv[])
{
	GLFWController c(argv[0]);
	c.reportVersions(std::cout);

	std::ifstream is("ExchangeRates.csv");

	std::string date;
	float rate1, rate2, rate3, rate4;
	char comma;
	std::cout << "First five lines:\n";
	int nLines = 0;
	while (is >> date >> rate1 >> comma >> rate2 >> comma >> rate3 >> comma >> rate4)
	{
		if (++nLines <= 5)
			std::cout << nLines << ' ' << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';
	}
	std::cout << "\nLast line:\n";
	std::cout << nLines << ' ' << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';

	// TODO: one or more ModelView dynamic allocations, adding
	//       each to the Controller using "c.addModel(...);"
	makeGrid(c, nLines-1);

	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);
	// Simplest case: Just tell the ModelView we want to see it all:
	ModelView::setMCRegionOfInterest(xyz);

	c.run();

	return 0;
}
