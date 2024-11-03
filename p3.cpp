//Aidan Ahmad
//p3.cpp
//Desc: Testing the BST class

#include<iostream>
#include "tree.h"

using namespace std;

const int SIZE = 25;

const int TEST_NUMS[SIZE] = {21, 49, 40, 14, 9, 32, 24, 29, 20, 14, 15,
                             49, 42, 31, 33, 22, 25, 38, 43, 12, 47,
                              22, 40, 41, 45};

const int FIND = 32;
const int MISSING = 55;
const int LEAF = 15;
const int ONECHILD = 20;
const int TWOCHILD = 24;

int main()
{
  BST tree;

  cout << "BST created" << endl << endl;
  for(int i = 0; i < SIZE; i++){
    if(!tree.insert(TEST_NUMS[i])){
      cout << TEST_NUMS[i] << " NOT inserted ";
    }else{
      cout << TEST_NUMS[i] << " inserted ";
    }
    cout << endl;
  }

  cout << endl << "Printing tree in post-order:" << endl;
  
  tree.postOrderTraversal();

  cout << endl << "Printing tree in order:" << endl;

  tree.inOrderTraversal();

  cout << endl << "Finding a key: " << FIND << endl;
  if(tree.findKey(FIND)){
    cout << "Key found! " << FIND << endl;
  }else{
    cout << "Key not found." << endl;
  }

  cout << endl << "Finding a key that doesn't exist: " << MISSING << endl;
  if(tree.findKey(MISSING)){
    cout << "Key found! " << MISSING << endl;
  }else{
    cout << "Key not found." << endl;
  }

  cout << endl << "Finding the height of the tree: " << endl;
  cout << tree.height();
  cout << endl;

  cout << endl << "Testing the copy constructor" << endl;
  cout << "Printing first tree: ";
  tree.inOrderTraversal();
  
  cout << endl << endl << "Copying tree...";
  BST tree2(tree);
  cout << endl << endl << "Printing second tree: ";
  tree.inOrderTraversal();

  cout << endl << endl << "Testing delete function. ";
  cout << endl << "Starting with a leaf, " << LEAF << endl;
  tree.deleteNode(LEAF);
  tree.inOrderTraversal();
  cout << endl;

  cout << endl << "Now deleting a node with one child, " << ONECHILD << endl;
  tree.deleteNode(ONECHILD);
  tree.inOrderTraversal();
  cout << endl;

  cout << endl << "Finally, deleting a node with two children, " << TWOCHILD;
  cout << endl;
  tree.deleteNode(TWOCHILD);
  tree.inOrderTraversal();
  cout << endl;

  cout << endl << "Now printing tree with values removed: " << endl;
  tree.inOrderTraversal();
  cout << endl;
  
  cout << endl << "Now testing assignment operator and assigning original" 
       << endl << "tree to the 2nd tree which should be the original:" << endl;
  tree = tree2;
  tree.inOrderTraversal();

  cout << endl;
  return 0;
}