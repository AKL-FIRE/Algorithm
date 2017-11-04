/*
 * main.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: apple
 */

#include "Algorithm.hpp"

int main()
{
	int a[5] = {3,5,2,1,6};
	int min,max;
	minmax(0,4,a,min,max);
	std::cout << min << "  " << max;
}


