#pragma once
#include "reqHandler.h"

extern RequestHandler rh;
//extern bool make_thread;

class QuickSort
{
public:
    QuickSort();
    void setMT_on();
    void setMT_off();
    static void quicksort(int* array, long left, long right);
    void check(int* test, int arrsize);
private:
    static bool make_thread;
};