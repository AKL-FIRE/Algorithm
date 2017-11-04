/*
 * Algorithm.hpp
 *
 *  Created on: Oct 3, 2017
 *      Author: apple
 */

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <iostream>

void perm(int m,int n,int *p)
{
	if (m == n)
	{
		for(int i = 1; i <= n; i++)
			std::cout << p[i] << "  ";
		std::cout << std::endl;
	}
	else
	{
		for(int j = m; j <= n; j++)
		{
			std::swap(p[j],p[m]);
			perm(m + 1,n,p);
			std::swap(p[j],p[m]);
		}
	}
}

void Permutations(int n)
{
	int *p = new int[n + 1];
	p[0] = 0;
	for(int i = 1; i <= n; i++)
		p[i] = i;
	perm(1,n,p);
}



#endif /* ALGORITHM_HPP_ */
