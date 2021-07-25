#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>

class MinMaxHeap {
  public:
    //Constructor
    MinMaxHeap();

    //Class Functions
    void Build();
    void Insert(int * value);
    bool Delete(int value);
    int FindMin();
    int FindMax();
    //Helper Functions
    void IncHeap_Size() { heap_size++; }
    void DecHeap_Size() { heap_size--; }
    int GetHeap_Size() { return heap_size; }

    void PrintHeap();

    bool FindValue(int value);
    int IndexOfValue(int value);
    
  private:
    int ** heap_arr;
    int heap_size;
    int lastNodeIndex;
    bool isBalanced;
};

#endif
