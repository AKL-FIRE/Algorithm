//
//  Algorithms.hpp
//  Chapter1
//
//  Created by Apple  on 10/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef Algorithms_hpp
#define Algorithms_hpp

#include <iostream>
#include <algorithm>

template <typename T>
int findElement(const T *elements,int size,const T &theElement)
{
    for(int i = 0;i < size;i++)
        if(elements[i] == theElement)
            return i;
    return -1;
}

template <typename T>
int BinarySearch(const T *elements,int size,const T &theElement)
{
    int high = size - 1, low = 0, current = (high + low) / 2;
    while(high >= low)
    {
        if(elements[current] == theElement)
            return current;
        if(elements[current] > theElement)
            high = current - 1;
        else
            low = current + 1;
        current = (high + low) / 2;
    }
    return -1;
}

template <typename T>
T* MergeSortedLists(const T *theElements,int size1,int size2)
{
    T *temp = new T[size1 + size2];
    int s = 0, t = size1,k = 0;
    while(s < size1 && t < size2 + size1)
    {
        if(theElements[s] <= theElements[t])
        {
            temp[k] = theElements[s];
            s++;
        }else
        {
            temp[k] = theElements[t];
            t++;
        }
        k++;
    }
    if(s == size1 && t != size2 + size1)
        std::copy(theElements + t, theElements + size2 + size1, temp + k);
    else if (s != size1 && t == size2 + size1)
        std::copy(theElements + s, theElements + size1, temp + k);
    return temp;
}

template <typename T>
void SelectionSort(T *theElements,int size)
{
    int index = 0, min = 0, mindata;
    for(int t = 0; t < size - 1; t++,index++)
    {
        mindata = theElements[index];
        min = index;
        for(int i = index; i < size - 1; i++)
        {
            if(theElements[i + 1] < mindata)
            {
                mindata = theElements[i + 1];
                min = i + 1;
            }
        }
        std::swap(theElements[index], theElements[min]);
    }
}

template <typename T>
void InsertSort(T *theElements,int size)
{
    for(int i = 1; i < size; i++)
    {
        T temp = theElements[i];
        int j = i - 1;
        while(j >= 0 && theElements[j] > temp)
        {
            theElements[j + 1] = theElements[j];
            j--;
        }
        theElements[j + 1] = temp;
    }
}

#endif /* Algorithms_hpp */
