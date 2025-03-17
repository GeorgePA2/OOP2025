#pragma once
class Sort
{
    int* vector;
    int minimum, maximum, nr_elemente;
public:
    // add constuctor
    Sort(int minimum, int maximum, int nr_elemente);
    Sort(int nr, int array[]);
    Sort(const char* sir);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
