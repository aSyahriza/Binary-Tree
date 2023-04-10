/*
* Author: Allam Syahriza
* Date: 4/9/2023
* Project: Binary Tree
* This project creates a binary tree of nodes with 
* integers as values. The user can add vallues, remove a value, 
* print, or search the tree
* 
*
*/

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

  cout << "Enter ADD, ADD BY FILE, REMOVE, PRINT, SEARCH, or QUIT" << endl;
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
    // Checks if user wants to remove a number
    if(strcmp(command, "REMOVE")==0){
      int num;
      cout << "Enter number to remove: " << endl;
      cin >> num;
      if(myTree.searchTree(myTree.getHead(),num)==false){
        cout << "Value not in tree" << endl;
        continue;
      }
      myTree.removeNode(myTree.getHead(),num);
      cout << "Value has been removed." << "\n" << endl;
    }

    // Check if the user wants to print the tree
    if(strcmp(command, "PRINT") == 0){
      myTree.print();
      cout << endl;
    }

    // Check if the user wants to search the tree for a number
    if(strcmp(command, "SEARCH") == 0){
      int num;
      cout << "Enter number you wish to search for: " << endl;
      cin >> num;
      if((myTree.searchTree(myTree.getHead(), num))==false){
        cout << "Value is not in tree." << endl;
      }
      else{
        cout << "Value is in tree." << endl;
      }
      cout << "\n" << endl;
    }
    // Quit
    if(strcmp(command, "QUIT") == 0){
      loop = false;
    }
  }  
  
  cout << "Program ended. " << endl;
  
}