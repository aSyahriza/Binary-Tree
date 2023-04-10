#include <iostream>
#include <cstring>

#include <vector> 

#include "tree.h"

using namespace std;

int main() {

  bool loop = true;
  Tree myTree;
  char command[20];
  char* fileName = new char[20];

  cout << "Enter ADD, ADD BY FILE, REMOVE, PRINT, or QUIT" << endl;
  cout << "\n" << endl;
  
  while(loop){
    cin.get(command,20,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    // Checks if the user wants to ADD a single number to the heap
    if(strcmp(command, "ADD") == 0){
      cout << "Enter numbers, seperated by space, within a range of 1-999)" << endl;
      int num;
      vector<int> vect;
      while( cin >> num) {
        vect.push_back(num);
        if (cin.peek() == '\n') {
          break;
        }
      }
      myTree.addVector(vect);
      cout << "Values have been added." << endl;
      cout << "\n";
      vect.clear();
    }
    // Checks if the user wants to read in a file of numbers seperated by a space
    if(strcmp(command, "ADD BY FILE") == 0){
      cout << "Enter a file name: " << endl;
      cin.get(fileName,20,'\n');
      cin.clear();
      cin.ignore(99999,'\n');
      myTree.addFile(fileName);
      cout << "\n";
      
    }

    if(strcmp(command, "PRINT") == 0){
      myTree.print();
    }
  }  
  
  cout << "Hello World!\n";
  
}