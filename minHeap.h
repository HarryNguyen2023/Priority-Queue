# include <vector>

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

// Define the class for the implementation of the min heap
template <class T>
class minHeap
{
    private:
    std::vector<T> minheap;
    void Heapify(int size, int index);
    void swap(T* a, T* b);

    public:
    void insert(T data);
    void remove(T data);
    void printHeap();
    T getMin();
    int getSize();
    void heapsort();
};

#endif