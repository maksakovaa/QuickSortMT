#include "quickSort.h"

QuickSort::QuickSort()
{
    setMT_off();
}

void QuickSort::setMT_off()
{
    make_thread = false;
}

void QuickSort::setMT_on()
{
    make_thread = true;
}

void QuickSort::quicksort(int *array, long left, long right, std::shared_ptr<std::promise<void>> prom)
{
    if(left >= right)
    {
        if (prom)
        {
            prom->set_value();
        }
        return;
    }
    
    long left_bound = left;
    long right_bound = right;
    long middle = array[(left_bound + right_bound) / 2];

    do {
        while(array[left_bound] < middle)
        {
            left_bound++;
        }
        while(array[right_bound] > middle)
        {
           right_bound--;
        }

        if (left_bound <= right_bound)
        {
            std::swap(array[left_bound], array[right_bound]);
            left_bound++;
            right_bound--;
        }
    } while (left_bound <= right_bound);
    if (left_bound < right)
    {
        auto promise_right = std::make_shared<std::promise<void>>();
        if(make_thread && (right_bound - left > 10000))
        {
            m_pool.push_task(std::bind(&QuickSort::quicksort, this, array, left, right_bound, prom), array, left, right_bound, prom);
            m_pool.start(array, left, right_bound, prom);
            quicksort(array, left_bound, right, prom);
        }
        else
        {
            quicksort(array, left, right_bound, nullptr);
            quicksort(array, left_bound, right, nullptr);
        }
        if (prom)
        {
            promise_right->get_future().wait();
        }
    }   
}

void QuickSort::check(int* test, int arrsize)
{
    std::cout << "Проверка сортировки...\n";
    bool sorted = true;
    for(long i = 0; i < arrsize - 1; ++i)
    {
        if (test[i] > test[i + 1])
        {
            sorted = false;
            break;
        }
    }
    if(sorted) std::cout << "Массив отсортирован\n";
    else std::cout << "Массив не отсортирован\n";
}