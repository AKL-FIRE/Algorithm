/*
 * main.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: apple
 */

#include "Graph.h"

int main()
{
	Graph<6>* a = new Graph<6> (9,true,65500);
	a->print();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << a->FindShortestPath(0,5);
}
