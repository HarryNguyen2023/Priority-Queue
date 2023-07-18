# Priority-Queue
## Author Harry Nguyen (Created 07/07/2023)

Priority queue is a very interesting data structure, that links the linear data structure with the tree data structure. Priority queue can be implemented by many data type of data structure, but min or max heap is the most commom one.

The min or max heap has a property that the left and right child od a node at position i in the lnear array is respectively the 2i + 1 and 2i + 2 keys. And we can create the heap by the operation call heapify, which sequentially find the maximum value between the current node, with its left and right child, then swap the postion if necessary.

Priority queue is implemented in many algorithm such as the famous heap sort of Djiska algorithm.

### References
[1]. Priority Queue, https://www.programiz.com/dsa/priority-queue.
