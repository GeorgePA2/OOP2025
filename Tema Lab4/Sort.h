#pragma once
class Sort
{
    int* vector;
    int nr_elemente;
public:
    // add constuctor
    Sort(int minimum, int maximum, int nr_elemente);
    Sort();
    Sort(int nr, int array[]);
    Sort(int nr, ...);
    Sort(const char* sir);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
