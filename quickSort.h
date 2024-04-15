#pragma once
#include "thPool.h"

class QuickSort
{
public:
    QuickSort();
    void setMT_on();
    void setMT_off();
    void quicksort(int* array, long left, long right, std::shared_ptr<std::promise<void>> prom);
    void check(int* test, int arrsize);
private:
    bool make_thread;
    ThreadPool pool;
};