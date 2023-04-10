


#include "tree.h"
#include <fstream>
#include <math.h> 

using namespace std;

Tree::Tree(){
  
}
Tree::~Tree(){
  
}

void Tree::addValue(Node* current, Node* newNode,int numOfLevels){
  // Checks if empty
  if(numOfNodes == 0){
    head = newNode;
    numOfNodes++;
    totalLevels = 1;
    return;
  }
  // Checks if number is smaller than current
  if(newNode->getValue()<=current->getValue()){
    // Adds to left child if empty
    if(current->getLeft()==NULL){
      current->setLeft(newNode);
      int temp = numOfLevels+1;
      if(temp > totalLevels){
        totalLevels = temp;
      }
      numOfNodes++;
    }
    else{
      // Further traverses if not empty
      // numOfLevels used for print
      int temp = numOfLevels+1;
      if(temp > totalLevels){
        totalLevels = temp;
      }
      addValue(current->getLeft(),newNode,temp);
    }
  }
  // Checks if number is larger than current
  if(newNode->getValue()>current->getValue()){
    // Adds to right child if empty
    if(current->getRight()==NULL){
      current->setRight(newNode);
      int temp = numOfLevels+1;
      if(temp > totalLevels){
        totalLevels = temp;
      }
      numOfNodes++;
    }
    // Further traverses
    else{
      int temp = numOfLevels+1;
      if(temp > totalLevels){
        totalLevels = temp;
      }
      addValue(current->getRight(),newNode,temp);
    }
  }
}

void Tree::addVector(vector<int> vect){
  // Takes in vector, for when user inputs sequence of integers
  // seperated by spaces
  for (int i = 0; i < vect.size(); i++){
    Node* newNode = new Node(vect[i]);
    if(numOfNodes == 0){
      head = newNode;
      numOfNodes++;
    }  
    else{
      addValue(head,newNode,1);
    }
  }
}
void Tree::addFile(char* fileName){
  // Checks if file exists
  ifstream tempFile;
  tempFile.open(fileName);
  
  if(tempFile){
    // Reads through every value in file, adds to heap
    cout << "File found." << endl;
    ifstream MyReadFile(fileName);
    int temp;
    while (MyReadFile >> temp){
      if(temp > 999){
        continue;
      }
      Node* newNode = new Node(temp);
      addValue(head,newNode,0);
    }
    cout << "Values have been added." << endl;
  }
  else{
    cout << "Unable to find file" << endl;
  }
}
Node* Tree::removeNode(Node* current, int num){
  // If current is the node to remove
  if(current->getValue() == num){
    // Checks how many children the node has
    if(current->getLeft()==NULL && current->getRight()==NULL){
      delete current;
      return NULL;
    }
    
    else if(current->getLeft()==NULL){
      return current->getRight();
      delete current;
    }
    else if(current->getRight()==NULL){
      return current->getLeft();
      delete current;
    }
    else{
      Node* temp = current->getLeft();
      int ctr = 0;
      while(temp->getRight()!=NULL){
        temp = temp->getRight();
        ctr++;
      }
      if(current->getRight()!=NULL){
        temp->setRight(current->getRight());
      }
      if(temp->getLeft()!=NULL){
        current->getLeft()->setRight(temp->getLeft());
      }
      temp->setLeft(current->getLeft());
      
      if(head->getValue()==num){
        head = temp;
      }
      
      
      Node* temp2 = current->getLeft();
      for(int i = 0; i < ctr-1;i++){
        temp2 = temp2->getRight();
      }
      temp2->setRight(NULL);
      delete current;
      return temp;
    }
  }
  else if(current->getLeft()->getValue()==num){
    current->setLeft(removeNode(current->getLeft(),num));
  }

  else if(current->getRight()->getValue()==num){
    current->setRight(removeNode(current->getRight(),num));
  }
  else if(num < current->getValue()){
    removeNode(current->getLeft(),num);
  }
  else if(num > current->getValue()){
    removeNode(current->getRight(),num);
  }
  return current;
}
bool Tree::searchTree(Node* current, int num){
  if(numOfNodes == 0){
    cout << "List is empty" << "\n" << endl;
    return false;
  }
  if(current->getValue() == num){
    return true;
  }
  // Reached the last child of tree, without encountering the 
  // number. Returns false.
  else if(current->getLeft()==NULL&&current->getRight() == NULL){
    return false;
  }
    // traverse into left child
  else if(num<=current->getValue()){
    return searchTree(current->getLeft(),num);
  }
    // traverse into right child
  else if(num>current->getValue()){
    return searchTree(current->getRight(),num);
  }
}
void Tree::print(){
  if(numOfNodes==0){
    cout <<"List is empty." << "\n" << endl;
    return;
  }
  recursePrint(head, 0);
}

void Tree::recursePrint(Node* current,int currentLevel){
  // Recurse into right child
  int newLevel = currentLevel + 1;
  if(currentLevel != totalLevels&& current!=NULL){
    recursePrint(current->getRight(), newLevel);
  }
  //Causes print to be more accurately spaced, but also becomes too spaced out in some cases
  /*if(current==NULL){
    if(currentLevel != totalLevels){
      recursePrint(NULL,newLevel);
    }
  }*/

  //Prints appropriate # of spaces
  for(int j = 0; j < currentLevel; j++){
    cout << "\t";
  }
  //Prints value
  if(current!=NULL){
    if(current->getValue()<1000)
      cout << current->getValue()<< endl;
  }
  else{
    cout << endl;
  }

  //Traverse into left child
  if(currentLevel != totalLevels&&current!=NULL){
    recursePrint(current->getLeft(), newLevel);
  }
  /*
  if(current==NULL){
    if(currentLevel != totalLevels){
      recursePrint(NULL,newLevel);
    }
  }*/

  
}


Node* Tree::getHead(){
  return head;
}