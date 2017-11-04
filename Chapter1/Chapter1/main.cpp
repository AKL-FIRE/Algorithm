//
//  main.cpp
//  Chapter1
//
//  Created by Apple  on 10/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#include "Algorithms.hpp"

int main(int argc, const char * argv[]) {
    
    int a[5] = {0,3,4,5,8};
    std::cout << findElement(a, 5, 5) << std::endl;
    std::cout << findElement(a, 5, 11) << std::endl;
    std::cout << BinarySearch(a, 5, 5) << std::endl;
    std::cout << BinarySearch(a, 5, 11) << std::endl;
    int ddd[12] = {0,3,4,5,8,2,3,5,7,8,9,10};
    int * p = MergeSortedLists(ddd, 5, 7);
    for(int i = 0;i < 12;i++)
        std::cout << *(p + i);
    std::cout << std::endl;
    int s[5] = {5,2,0,4,7};
    SelectionSort(s,5);
    int h[5] = {5,2,0,4,7};
    InsertSort(h,5);
    return 0;
}
