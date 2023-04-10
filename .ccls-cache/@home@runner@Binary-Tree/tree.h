#include <iostream>
#include <cstring>

#include "node.h"

class Tree{

public:
  Tree();
  ~Tree();
  void addValues(int num);
  void addFile(char* fileName);
  void removeNode(int num);
  bool searchTree(int num);
  void printHeap();
  void recurseHeap(int index, int levels, int currentLevel);

  int numOfNodes;
  

private:
  Node* head;
  

};