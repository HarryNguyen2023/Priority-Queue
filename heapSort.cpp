#include <iostream>
#include <vector>
using namespace std;

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify for min heap algorithm
void heapify(vector<int>& nums, int size, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Find the largest numbser among the 3 above
    if(left < size && nums[left] > nums[largest])
        largest = left;

    if(right < size && nums[right] > nums[largest])
        largest = right;

    // Swap the position if needed
    if(largest != i)
    {
        Swap(&nums[i], &nums[largest]);
        heapify(nums, size, largest);
    }
}

// Heap sort algorithm
void heapsort(vector<int>& nums)
{
    for(int i = nums.size() / 2 - 1; i >= 0 ; --i)
        heapify(nums, nums.size(), i);

    for(int i = nums.size() - 1; i >= 0; --i)
    {
        Swap(&nums[i], &nums[0]);
        heapify(nums, i, 0);
    }
}

int main()
{
    // Initiate the input vector
    vector<int> nums = {-1, 2, 1, -4, 8, 9, 5, 6, -3, -10, 26, 33};
    heapsort(nums);
    // Display to the terminal
    cout<<"Element of the list fater Heap sort: ";
    for(auto& i:nums)
    {
        std::cout<<i<<" ";
    }
    cout<<std::endl;
    return 0;
}