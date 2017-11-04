//
//  main.cpp
//  floyd
//
//  Created by Apple  on 11/10/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#include <iostream>

void Floyd(int a[3][3],int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);
}

int main(int argc, const char * argv[]) {
    int a[3][3] = {{0,2,9},{8,0,6},{1,65500,0}};
    Floyd(a, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
