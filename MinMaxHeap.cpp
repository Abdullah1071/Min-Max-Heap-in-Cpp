#include <iostream>
#include <ctime>

#include "MinMaxHeap.h"

//Constructor
MinMaxHeap::MinMaxHeap() {
  heap_arr = new int*[100];
  heap_size = 0;
  lastNodeIndex = 0;
  isBalanced = true;
}

//Class Methods
//Function to build the Min-Max Heap
void MinMaxHeap::Build(){
  int maxNodesInLevel = 1;
  int nodesInLevel = 0;
  for(int lcv = 0; lcv <= GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      std::cout << *heap_arr[lcv] <<" ";
      nodesInLevel++;
    }
    if(nodesInLevel == maxNodesInLevel) {
      std::cout << std::endl;
      maxNodesInLevel = maxNodesInLevel * 2;
      nodesInLevel = 0;
    }
  }
}
//Function to insert the value in the heap
void MinMaxHeap::Insert(int * value) {
  if(!FindValue(*value)) {
    if(heap_arr[0] == nullptr) {
      // std::cout <<"Empty Array, adding first item.\n";
      heap_arr[0] = value;
    }
    else {
      heap_arr[GetHeap_Size()] = value;
    }
    IncHeap_Size();
  }
  else {
    std::cout << "Error: Duplicate value: " <<*value <<" attempted to be inserted into the heap.\n";
  }
}
//Function to delete a element
bool MinMaxHeap::Delete(int value) {
  int index = IndexOfValue(value);
  int * lastNode = heap_arr[GetHeap_Size()];

  //No Value Found
  if(index == -1) {
    return (false);
  }

  heap_arr[index] = lastNode;
  lastNode = nullptr;

  DecHeap_Size();

  return true;
}
//Function to find the minimum element in the heap
int MinMaxHeap::FindMin()
{
  int min = *heap_arr[0];
  int length = sizeof(*heap_arr)/sizeof(*heap_arr[0]);
  for(int j = 0; j < length; j++)
  {
    if(*heap_arr[j] < min)
    {
      min = *heap_arr[j];
    }
  }
  return min;
}
//Function to find the maximum element in the heap
int MinMaxHeap::FindMax()
{
  int max = *heap_arr[0];
  for(int j = 0; j < GetHeap_Size(); j++)
  {
    if(*heap_arr[j] > max)
    {
      max = *heap_arr[j];
    }
  }
  return max;
}
//Function for printing heap
void MinMaxHeap::PrintHeap() {
  std::cout <<"HEAP: ";
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      std::cout << *heap_arr[lcv] <<", ";
    }
  }
  std::cout << std::endl;
}
//Function for Finding a specific value
bool MinMaxHeap::FindValue(int value) {
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(*heap_arr[lcv] == value) {
        return(true);
      }
    }
  }
  return(false);
}
//Function for Finding index of any value
int MinMaxHeap::IndexOfValue(int value) {
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(*heap_arr[lcv] == value) {
        return(lcv);
      }
    }
  }
  return(-1);
}
