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

void QuickSort::quicksort(int *array, long left, long right)
{
    if(left >= right) return;
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

    if(make_thread && (right_bound - left > 10000))
    {
        auto f = rh.pushRequest(QuickSort::quicksort, array, left, right_bound);
        quicksort(array, left_bound, right);
    }
    else
    {
        quicksort(array, left, right_bound);
        quicksort(array, left_bound, right);
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