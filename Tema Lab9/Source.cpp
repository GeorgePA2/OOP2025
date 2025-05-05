#include "Map.h"
#include <iostream>

using namespace std;


int main()
{
    Map<int, const char*> m;
    Map<int, const char*> m2;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    m2[10] = "zece";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    m.Set(10, "zece");
    const char* basescu = "Basescu";
    m.Get(10, basescu);
    printf("Nume: %s \n", basescu);
    if (m.Delete(40)) {
        for (auto [key, value, index] : m)
        {
            printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
        }
    }
    //m.Clear();
    printf("Exista %d elemente in mapa \n", m.Count());
    if (m.Includes(m2)) {
        for (auto [key, value, index] : m2)
        {
            printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
        }
    }
    return 0;
   
}
