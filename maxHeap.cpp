#include <iostream>
#include <limits.h>
#include "maxHeap.h"

// Function to swap the value of 2 pointer in the heap
template <typename T>
void maxHeap<T>::swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Function to heapify the heap
template <typename T>
void maxHeap<T>::Heapify(int size, int index)
{
    // Assign the leaft and right child of the current node position
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    // Find the largest between the three nodes
    if(left < size && maxheap[left] > maxheap[largest])
        largest = left;
    if(right < size && maxheap[right] > maxheap[largest])
        largest = right;
    
    // Swap the position of the current node with the largest node
    if(largest != index)
    {
        swap(&maxheap[index], &maxheap[largest]);
        Heapify(size, largest);
    }
}

// Function to insert a new node into the heap
template <typename T>
void maxHeap<T>::insert(T data)
{
    // Insert the new node at the end of the array
    if(maxheap.size() == 0)
        maxheap.push_back(data);
    else
    {
        maxheap.push_back(data);
        // Heapify the array
        for(int i = maxheap.size() / 2 - 1; i >= 0; --i)
            Heapify(maxheap.size(), i);
    }
}

// Function to display the heap 
template <typename T>
void maxHeap<T>::printHeap()
{
    // Check if the heap is empty
    if(maxheap.size() == 0)
        return;
    std::cout<<"Elements in the max heap: ";
    for(int i = 0; i < maxheap.size(); ++i)
        std::cout<<maxheap[i]<<" ";
    std::cout<<std::endl;
}

// Function to delete a node in the heap
template <typename T>
void maxHeap<T>::remove(T data)
{
    // Search for the position of the node to be deleted in the array
    int i;
    for(i = 0; i < maxheap.size(); ++i)
    {
        if(maxheap[i] == data)
            break;
    }
    // Check if the node is presented in the heap
    if(i == maxheap.size())
    {
        std::cout<<"Node "<<data<<" not found!"<<std::endl;
        return;
    }
    // Swap the deleted node with the last node in the heap
    swap(&maxheap[i], &maxheap[maxheap.size() - 1]);
    // Pop it out
    maxheap.pop_back();
    // Heapify the array once again
    for(int j = maxheap.size() / 2 - 1; j >= 0; --j)
        Heapify(maxheap.size(), j);
}

// Function to get the maximum number of the heap
template <typename T>
T maxHeap<T>::getmax()
{
    if(maxheap.size() == 0)
        return INT_MIN;
    return maxheap[0];
}

// Function to get the size of the heap array
template <typename T>
int maxHeap<T>::getSize()
{
    return maxheap.size();
}

// Function to sort the array using the heap property
template <typename T>
void maxHeap<T>::heapsort()
{
    // Craete the max heap if it is not done yet
    // for(int i = maxheap.size() / 2 - 1; i >= 0 ; --i)
    //     Heapify(maxheap.size(), i);
    // Heap sort algorithm
    for(int i = maxheap.size() - 1; i >= 0; i--)
    {
        swap(&maxheap[i], &maxheap[0]);
        Heapify(i, 0);
    }
}

int main()
{
    // Initiate the heap 
    maxHeap<int> mheap;
    int random[] = {23, 76, 3, 4, 8, 5, 90, 101, 32, 22, 27, 35, 109};
    for(int i = 0; i < sizeof(random)/sizeof(int); ++i)
        mheap.insert(random[i]);
    // Display the the heap
    mheap.printHeap();
    // Delete a few node in the heap
    mheap.remove(35);
    mheap.remove(22);
    mheap.remove(510);
    // Display the heap once again
    mheap.printHeap();
    // Get the maximum element in the heap
    std::cout<<"The maximum element in the heap is: "<<mheap.getmax()<<std::endl;
    // Get the size of the heap
    std::cout<<"Size of the heap is: "<<mheap.getSize()<<std::endl;
    // Sort the heap array
    mheap.heapsort();
    mheap.printHeap();

    return 0;
}