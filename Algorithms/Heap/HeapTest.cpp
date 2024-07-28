/* Heap Algorithm Test code
 *
 * [With 100,000,000 data sorting result]
 * Heap sort time = 45.40825660 (slow due to pop algorighm)
 * STL sort time = 18.78390440
 */

#include "MinHeap.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;

void validation(int *arr, int *arr2)
{
    for (int i = 0; i < HEAPSIZE - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "STL validate failed..!" << endl;
            break;
        }
    }

    for (int i = 0; i < HEAPSIZE - 1; i++)
    {
        if (arr2[i] > arr2[i + 1])
        {
            cout << "Heap validate failed..!" << endl;
            break;
        }
    }

    for (int i = 0; i < HEAPSIZE; i++)
    {
        if (arr[i] != arr2[i])
        {
            cout << "arr:" << arr[i] << " != " << "arr2:" << arr2[i] << endl;
            break;
        }
    }
}

int main(void)
{
    MinHeap mh;
    mh.init();

    int *arr = new int[HEAPSIZE];
    int *arr2 = new int[HEAPSIZE];
    mh.init();
    for (int i = 0; i < HEAPSIZE; i++)
    {
        int val = rand();
        arr[i] = val;
        mh.push(arr[i]);
    }

    /* Heap sort test */
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < HEAPSIZE; i++)
        arr2[i] = mh.pop();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end - start;
    cout << fixed << setprecision(8) << "Heap sort time = " << elapsed2.count() << endl;

    /* STL sort test */
    start = std::chrono::high_resolution_clock::now();
    sort(arr, arr + HEAPSIZE);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end - start;
    cout << fixed << setprecision(8) << "STL sort time = " << elapsed1.count() << endl;

    validation(arr, arr2);

    mh.free();
    delete (arr);
    delete (arr2);
    return 0;
}