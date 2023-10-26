#include<iostream>

#include<cstdlib>
#include<ctime>

#include "MatrixJob.h"
#include "MatrConsoleIO.h"

int main(int argc, char* argv[])
{
	srand(time(0));
	//int* vect = nullptr; //1-dimentional array
	demoSum();
	demoDiff();
	demoProduct();
	demoProductNum();
	demoDiv();
	demoTranspose();
	return EXIT_SUCCESS;
}