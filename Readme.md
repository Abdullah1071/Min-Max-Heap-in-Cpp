Min-Max Heap:
Min nodes: even levels (0, 2, 4...)
Max nodes: odd levels (1, 3, 5...)

General Requirements:
A min-max heap is a data structure that supports both deleteMin and deleteMax in O(log N ) per
operation. The structure is identical to a binary heap, but the heap-order property is that for any node, X,
at even depth, the element stored at X is smaller than the parent but larger than the grandparent (where
this makes sense), and for any node X at odd depth, the element stored at X is larger than the parent
but smaller than the grandparent.

Using an array to represent the min-max heap structure (in the same way as for min heap or max
heap), implement the following operations.
1. buildHeap : Builds a min-max heap from a list of naturals read from standard input.
2. findMin and findMax : Returns the minimum (resp the maximum) element.
3. insertHeap : Inserts a new element into the min-max heap.
4. deleteMin and deleteMax : Deletes the minimum (resp the maximum) element.

How to Run:
To run this program takes two arguments on the command line
First: output file
Second: Text file having data to build a Min-Max Heap.

Run the following commands to run this program
	make
Then
	./MinMaxHeap data.txt
