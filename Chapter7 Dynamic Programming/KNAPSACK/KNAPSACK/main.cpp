//
//  main.cpp
//  KNAPSACK
//
//  Created by Apple  on 11/10/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>


void Knapsack(std::vector<unsigned int>& size,std::vector<unsigned int>& value,unsigned int capacity)
{
    size_t n = size.size();
    unsigned int **V = new unsigned int*[size.size() + 1];
    for(int i = 0; i < size.size() + 1; i++)
        V[i] = new unsigned int[capacity + 1];
    for(int i = 0; i <= n; i++)
        V[i][0] = 0;
    for(int j = 0; j <= capacity; j++)
        V[0][j] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= capacity ;j++)
        {
            V[i][j] = V[i - 1][j];
            if(j >= size[i - 1])
                V[i][j] = std::max(V[i][j], V[i - 1][j - size[i - 1]] + value[i - 1]);
        }
    for(int i = 0; i <= n; i++)
    {
        std::cout  << std::endl;
        for(int j = 0; j <= capacity ;j++)
            std::cout << V[i][j] << "   ";
    }
            
}

int main(int argc, const char * argv[]) {
    std::vector<unsigned int> size = {2,3,4,5};
    std::vector<unsigned int> value = {3,4,5,7};
    Knapsack(size, value, 9);
    return 0;
}
