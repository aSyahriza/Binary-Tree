#include "tree.h"
#include <fstream>

using namespace std;

Tree::Tree(){
  
}
Tree::~Tree(){
  
}

void Tree::addValue(Node* current, Node* newNode){
  if(numOfNodes == 0){
    head = newNode;
    numOfNodes++;
    return;
  }
  if(newNode->getValue()<=current->getValue()){
    if(current->getLeft()==NULL){
      current->setLeft(newNode);
      numOfNodes++;
    }
    else{
      addValue(current->getLeft(),newNode);
    }
  }
  if(newNode->getValue()>current->getValue()){
    if(current->getRight()==NULL){
      current->setRight(newNode);
      numOfNodes++;
    }
    else{
      addValue(current->getRight(),newNode);
    }
  }
}

void Tree::addVector(vector<int> vect){
  for (int i = 0; i < vect.size(); i++){
    Node* newNode = new Node(vect[i]);
    if(numOfNodes == 0){
      head = newNode;
      numOfNodes++;
    }  
    else{
      addValue(head,newNode);
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
      addValue(head,newNode);
    }
    cout << "Values have been added." << endl;
  }
  else{
    cout << "Unable to find file" << endl;
  }
}
void Tree::removeNode(int num){
  
}
bool Tree::searchTree(int num){
  
}
void Tree::print(){
  if(numOfNodes==0){
    cout <<"List is empty." << "\n" << endl;
    return;
  }
  recursePrint(head,1);
}
void Tree::recursePrint(Node* current,int currentLevel){
  if(current->getRight()!=NULL){
    int newLevel = currentLevel + 1;
    recursePrint(current->getRight(),newLevel);
  }
  
  for(int j = 0; j < currentLevel-1; j++){
    cout << "\t";
  }

  cout << current->getValue()<< endl;

  if(current->getLeft()!=NULL){
    int newLevel = currentLevel + 1;
    recursePrint(current->getLeft(),newLevel);
  }

  
}
