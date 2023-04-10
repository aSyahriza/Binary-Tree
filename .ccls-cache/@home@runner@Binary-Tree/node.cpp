#include "node.h"


Node::Node(){
value = 0;    
left = NULL;
right = NULL;
}
Node::Node(int valueP){
  value = valueP;
  left = NULL;
  right = NULL;
}
Node::~Node(){
  left = NULL;
  right = NULL;
}
int getValue();
Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}
void Node::setLeft(Node* leftP){
  left = leftP;
}
void Node::setRight(Node* rightP){
  right = rightP;
}
