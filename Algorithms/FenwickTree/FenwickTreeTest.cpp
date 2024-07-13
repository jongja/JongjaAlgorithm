/* Fenwick Tree Algorithm Test code
 *
 * [With 100,000,000 data]
 * Simple Sum : 4999999850000001, time = 0.17877820 s
 * Fenwick tree : 4999999850000001, time = 0.00000130 s
 */

#include <iostream>
#include <chrono>
#include <iomanip>
#include "FenwickTree.h"
using namespace std;

int *arr;

void arrInit(void)
{
    arr = new int[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
        arr[i] = i;
}

ull simpleSum(int n)
{
    ull result = 0;

    for (int i = 0; i < n; i++)
        result += arr[i];

    return result;
}

int main(void)
{
    Fenwick fen;
    arrInit();

    int how = ARR_SIZE - 1;
    fen.init(arr, how);

    /* Simple sum test */
    auto start = std::chrono::high_resolution_clock::now();
    ull res1 = simpleSum(how);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end - start;
    cout << fixed << setprecision(8) << "Simple Sum : " << res1 << ", time = " << elapsed1.count() << endl;

    /* Fenwick tree sum test */
    start = std::chrono::high_resolution_clock::now();
    ull res2 = fen.sumZeroto(how);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end - start;
    cout << fixed << setprecision(8) << "Fenwick tree : " << res2 << ", time = " << elapsed2.count() << endl;

    delete arr;
    delete fen.fen_arr;
    return 0;
}