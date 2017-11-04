//
//  main.cpp
//  majority
//
//  Created by LCY  on 25/10/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#include <iostream>

int candidate(int m,int *A,int n)
{
    int j = m;
    int c = A[m];
    int count = 1;
    while(j < n && count > 0)
    {
        j++;
        if(A[j] == c)
            count++;
        else
            count--;
    }
    if(j == n)
        return c;
    else
        return candidate(j + 1, A, n);
}

int Majority(int *A,int n)
{
    int c = candidate(1,A,n);
    int count = 0;
    for(int j = 1; j <= n; j++)
        if(A[j] == c)
            count++;
    if(count > (n / 2))
        return c;
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    int A[7] = {1,3,2,3,3,4,3};
    std::cout << "The majority element is : " << Majority(A, 7) << std::endl;
    return 0;
}
