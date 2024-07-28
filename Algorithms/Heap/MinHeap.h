#pragma once

/* Heap.h
 * Heap Algorithm using structure module
 *
 * Use case - Sorting, organize data.
 */

#define HEAPSIZE 100000000

struct MinHeap
{
    int *heap = nullptr;
    int size;

    void init(void)
    {
        if (heap) delete(heap);
        heap = new int[HEAPSIZE + 1];
        size = 0;
    }

    void push(int data)
    {
        int cur = ++size;

        while(cur != 1 && heap[cur >> 1] > data)
        {
            heap[cur] = heap[cur >> 1];
            cur >>= 1;
        }

        heap[cur] = data;
    }

    int pop(void)
    {
        int ret = heap[1];

        int e = heap[size--];
        int cur = 1, ch = 2;

        while(ch < size)
        {
            if(ch <= size && heap[ch] > heap[ch + 1]) ch++;
            if(e <= heap[ch]) break;
            heap[cur] = heap[ch];
            cur = ch;
            ch <<= 1;
        }

        heap[cur] = e;

        return ret;
    }

    void free(void)
    {
        delete(heap);
    }
};
