#include "quickSort.h"
#include "arrayGen.h"
#include "timer.h"

using namespace std;

//bool make_thread = false;
RequestHandler rh;
ArrayCreator Rand_arr;
TimeCounter Timer;
QuickSort Sort;

int main()
{
    Sort.setMT_on();
    long arr_size = 100000000;
    Timer.start();
    int* array = Rand_arr.createArray(arr_size);
    Timer.stop();
    
    cout << "Массив на " << arr_size << " элементов сгенерирован за " << Timer.result() << " секунд" << endl;

    Timer.start();
    Sort.quicksort(array, 0, arr_size);
    Timer.stop();
    cout << "Время многопоточной сортировки: " << Timer.result() << " секунд" << endl;
    
    Sort.check(array, arr_size);

    Sort.setMT_off();
    Timer.start();
    array = Rand_arr.createArray(arr_size);
    Timer.stop();
    cout << "Массив на " << arr_size << " элементов сгенерирован за " << Timer.result() << " секунд" << endl;
    
    Timer.start();
    Sort.quicksort(array, 0, arr_size);
    Timer.stop();
    cout << "Время однопоточной сортировки: " << Timer.result() << " секунд" << endl;
    
    Sort.check(array, arr_size);
    return 0;
}
