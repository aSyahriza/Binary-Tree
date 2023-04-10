#include <iostream>


class Node{

public: 
  Node();
  Node(int valueP);
  ~Node();
  int getValue();
  Node* getLeft();
  Node* getRight();
  void setLeft(Node*);
  void setRight(Node*);
private:
  Node* left;
  Node* right;
  int value;
};
