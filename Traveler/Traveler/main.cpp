//
//  main.cpp
//  Traveler
//
//  Created by Apple  on 23/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//
#include <iostream>
#define MAX 1000
typedef struct graph
{
    int **data;
    int numberOfVertices;
    int numberOfEdge;
    int *reach;
    int *partialTour;
    int *bestTour;
    int shortestDistance;
    int currentDistance;
    
    void init()
    {
        std::cout << "输入顶点数和边数：" << std::endl;
        std::cin >> numberOfVertices >> numberOfEdge;
        data = new int* [numberOfVertices];
        for(int i = 0; i < numberOfVertices; i++)
            data[i] = new int[numberOfVertices];
        
        reach = new int[numberOfVertices];
        for(int i = 0; i < numberOfVertices; i++)
            reach[i] = 0;
        
        for(int i = 0; i < numberOfVertices; i++)
            for(int j = 0; j < numberOfVertices; j++)
                data[i][j] = -1;
        
        int a,b,c;
        for(int i = 0; i < numberOfEdge; i++)
        {
            std::cout << i << ":输入两个端点和他们的权值:" << std::endl;
            std::cin >> a >> b >> c;
            data[a][b] = c;
            data[b][a] = c;
        }
    }
    
    void dfs(int vertex)
    {
        reach[vertex] = 1;
        std::cout << vertex << std::endl;
        for(int i = 0; i < numberOfVertices; i++)
            if(data[vertex][i] != -1 && reach[i] == 0)
                dfs(i);
    }
    
    int salseman()
    {
        partialTour = new int [numberOfVertices];
        bestTour = new int [numberOfVertices];
        for(int i = 0; i < numberOfVertices ;i++)
            partialTour[i] = i;
        
        currentDistance = 0;
        shortestDistance = MAX;
        
        TSPTravel(1);
        return shortestDistance;
    }
    
    void TSPTravel(int currentLevel)
    {
        if(currentLevel == numberOfVertices - 1)
        {
            if(data[partialTour[numberOfVertices - 2]][partialTour[numberOfVertices - 1]] != -1 && data[partialTour[numberOfVertices - 1]][partialTour[0]] != -1 && (currentDistance + data[partialTour[numberOfVertices - 2]][partialTour[numberOfVertices - 1]] + data[partialTour[numberOfVertices - 1]][0] < shortestDistance))
            {
                std::copy(partialTour,partialTour + numberOfVertices, bestTour);
                shortestDistance = currentDistance + data[partialTour[numberOfVertices - 2]][numberOfVertices - 1] + data[partialTour[numberOfVertices - 1]][0];
            }
        }else
        {
            for(int j = currentLevel; j < numberOfVertices; j++)
                if(data[partialTour[currentLevel - 1]][partialTour[j]] != -1 && (currentDistance + data[partialTour[currentLevel - 1]][partialTour[j]] < shortestDistance))
                {
                    std::swap(partialTour[currentLevel],partialTour[j]);
                    //for(int i = 0; i < numberOfVertices; i++)
                        //std::cout << partialTour[i];
                    //std::cout << std::endl;
                    currentDistance += data[partialTour[currentLevel - 1]][partialTour[currentLevel]];
                    TSPTravel(currentLevel + 1);
                    currentDistance -= data[partialTour[currentLevel - 1]][partialTour[currentLevel]];
                    std::swap(partialTour[currentLevel], partialTour[j]);
                    //for(int i = 0; i < numberOfVertices; i++)
                        //std::cout << partialTour[i];
                    //std::cout << std::endl;
                }
        }
    }
    
}graph;



int main()
{
    graph a;
    a.init();
    int *bestTour = nullptr;
    std::cout << a.salseman() << std::endl;
    bestTour = a.bestTour;
    for(int i = 0; i < a.numberOfVertices; i++)
        std::cout << bestTour[i];
}
