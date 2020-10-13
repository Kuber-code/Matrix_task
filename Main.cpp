#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint> 
#include "Matrix.h"


int parseInputArguments(int argc, char ** argv, uint32_t & rows, uint32_t & columns, uint32_t & scale)
{
	int parsedArguments;
	if (argc > 3) 
	{
		rows = atoi(argv[1]);
		columns = atoi(argv[2]);
		scale = atoi(argv[3]);
		parsedArguments = 3;
	}
	else
	{
		parsedArguments = 0;
	}
	return parsedArguments;
}

int main(int argc, char ** argv)
{
	Matrix * pMatrix;
	Matrix * pScaledMatrix;
	uint32_t rows, columns;
	uint32_t scale = 1;
	// Accepts input parameters either as program execution arguments
	int parsedArguments = parseInputArguments(argc, argv, rows, columns, scale);

    srand(time(NULL));

	if (parsedArguments == 0) 
	{
    	// Accepts input parameters interactively (line by line)
		pMatrix = new Matrix();
		pMatrix->createWithUserData(scale);

	}
	else
	{
		pMatrix = new Matrix(rows, columns);
	}
	
	std::cout << std::endl << "Source matrix:" << std::endl;
	pMatrix->fillWithRandomData();
	pMatrix->display();

	std::cout << std::endl << "Scale:  " << scale << std::endl;

	pScaledMatrix = pMatrix->createScaleMatrix(scale);
	std::cout << std::endl << "Destination matrix:" << std::endl;
	pScaledMatrix->display();

	system("PAUSE");

	delete pMatrix;
	delete pScaledMatrix;
	
	return 0;
}
