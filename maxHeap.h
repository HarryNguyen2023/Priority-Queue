# include <vector>

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// Define the class for the implementation of the max heap
template <class T>
class maxHeap
{
    private:
    std::vector<T> maxheap;
    void Heapify(int size, int index);
    void swap(T* a, T* b);

    public:
    void insert(T data);
    void remove(T data);
    void printHeap();
    T getmax();
    int getSize();
    void heapsort();
};

#endif