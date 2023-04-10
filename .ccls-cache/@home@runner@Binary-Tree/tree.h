#include <iostream>
#include <cstring>

#include <vector>

using namespace std;

#include "node.h"

class Tree{

public:
  Tree();
  ~Tree();
  void addValue(Node* current, Node* newNode);
  void addVector(vector<int> vect);
  void addFile(char* fileName);
  void removeNode(int num);
  bool searchTree(int num);
  void print();
  void recurseHeap(Node* current, int currentLevel);

  int numOfNodes;
  

private:
  Node* head;
  

};