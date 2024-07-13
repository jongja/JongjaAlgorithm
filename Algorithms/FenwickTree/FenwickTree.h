#pragma once

/* FenwickTree.h
 * Fenwick Tree Algorithm using structure module
 *
 * Use case - Sum from A to B.
 */

#define ARR_SIZE 100000000

typedef unsigned long long ull;

struct Fenwick
{
    ull *fen_arr; /* Data type is very important */
    int size;

    void init(int *arr, int s)
    {
        fen_arr = new ull[ARR_SIZE];
        size = s + 1;
        for (int i = 0; i < s + 1; i++)
            fen_arr[i] = 0;

        for (int i = 0; i < s; i++)
            update(i, arr[i]);
    }

    void update(int n, int val)
    {
        int cur = n + 1;
        while (cur < size)
        {
            fen_arr[cur] += val;

            /* Bring Two's complement number for
             * getting "1" position of b'cur
             * b'10100(cur) --> b'01100(-cur) & b'10100(cur)
             *                  = 00100
             */
            cur = cur + (cur & -cur);
        }
    }

    ull sumZeroto(int n)
    {
        ull result = 0;
        int cur = n;

        while (cur > 0)
        {
            result += fen_arr[cur];
            cur = cur - (cur & -cur);
        }

        return result;
    }

    ull sumBetween(int a, int b)
    {
        return sumZeroto(b) - sumZeroto(a);
    }
};