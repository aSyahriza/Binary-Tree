#include <iostream>
#include <cstring>

#include <vector>

using namespace std;

#include "node.h"

class Tree{

public:
  Tree();
  ~Tree();
  void addValue(Node* current, Node* newNode, int numOfLevels);
  void addVector(vector<int> vect);
  void addFile(char* fileName);
  Node* removeNode(Node* current, int num);
  bool searchTree(Node* current, int num);
  void print();
  void recursePrint(Node* current, int currentLevel);
  Node* getHead();

  
  

private:
  int totalLevels;
  int numOfNodes = 0;
  Node* head;
  

};