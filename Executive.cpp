#include <iostream>
#include <string>
#include <fstream>

#include "MinMaxHeap.h"
#include "Executive.h"

#define MAXINPUT 7

Executive::Executive(std::string path) {
  filePath = path;
}

int Executive::menuInput() {
  int choice;

  std::cout << "\nPlease choose one of the following commands: \n";
  std::cout << "1. Build Heap \n";
  std::cout << "2. Insert \n";
  std::cout << "3. Find Min \n";
  std::cout << "4. Find Max \n";
  std::cout << "5. Delete Min \n";
  std::cout << "6. Delete Max \n";
  std::cout << "7. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Build Heap
      case 1: {
        std::cout <<"Output: \n";
        mmHeap.Build();
        std::cout << std::endl;
        break;
      }
      //Insert
      case 2: {
        int input;
        std::cout << "Please enter the value which you want to enter into the MinMaxHeap: ";
        std::cin >> input;
        int * value = new int(input);
        mmHeap.Insert(value);
        mmHeap.Build();
        break;
      }
      //Minimum Element in the Min-Max heap
      case 3: {
        int min = mmHeap.FindMin();
        std::cout << "\nMinimum Element in the heap is " << min << "\n";
        std::cout << std::endl;
        break;
      }
      //Maximum Element in the Min-Max heap
      case 4: {
        int max = mmHeap.FindMax();
        std::cout << "\nMaximum Element in the heap is " << max << "\n";
        std::cout << std::endl;
        break;
      }
      //Delete Minimum Element in the Min-Max heap
      case 5: {
        int min = mmHeap.FindMin();
        std::cout << "Output: ";
        if(mmHeap.Delete(min)) {
          std::cout << "Deletion was successful.\n";
        }
        else {
          std::cout << "Deletion failed. The value: " << min <<" is not present in the tree.\n";
        }
        break;
      }
      //Delete Maximum Element in the Min-Max heap
      case 6: {
        int max = mmHeap.FindMax();
        std::cout << "Output: ";
        if(mmHeap.Delete(max)) {
          std::cout << "Deletion was successful.\n";
        }
        else {
          std::cout << "Deletion failed. The value: " << max <<" is not present in the tree.\n";
        }
        break;
      }
      //Exit
      case 7: {
        std::cout <<"Output: Bye!!!\n";
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and " <<MAXINPUT <<".\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  // pq = *mmHeap;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
      }
      else {
        int strInt = std::stoi(input);
        int * value = new int(strInt);
        mmHeap.Insert(value);
        input = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
