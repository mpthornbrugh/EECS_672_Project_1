// project1.c++

#include <iostream>
#include <fstream>
#include "GLFWController.h"
#include "ModelView.h"

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
			std::cout << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';
	}
	std::cout << "\nLast line:\n";
	std::cout << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';
	return 1;

	// TODO: one or more ModelView dynamic allocations, adding
	//       each to the Controller using "c.addModel(...);"

	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);
	// Simplest case: Just tell the ModelView we want to see it all:
	ModelView::setMCRegionOfInterest(xyz);

	c.run();

	return 0;
}
