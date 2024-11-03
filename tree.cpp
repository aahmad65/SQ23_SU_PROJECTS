//Aidan Ahmad
//tree.cpp
//File for tree.h methods

#include "tree.h"

using namespace std;

BST::TreeNode* BST::copyTree(const TreeNode* other)
{
  if(other == nullptr){
    return nullptr;
  }else{
    TreeNode* tree = new TreeNode;
    tree->key = other->key;
    tree->left = copyTree(other->left);
    tree->right = copyTree(other->right);
    return tree;
  }
}

bool BST::insert(TreeNode*& tree, int key)
{
  if(tree == nullptr){
    tree = new TreeNode;
    tree->key = key;
    tree->left = nullptr;
    tree->right = nullptr;
    return true;
  }else if(tree->key == key){
    return false;
  }else if(tree->key > key){
    return insert(tree->left, key);
  }else{
    return insert(tree->right, key);
  }

}

void BST::destructor(TreeNode*& tree)
{
  if(tree != nullptr){
    destructor(tree->left);
    destructor(tree->right);
    delete tree;
    tree = nullptr;
  }
}

bool BST::findKey(TreeNode* tree, int key)
{
  if(tree == nullptr){
    return false;
  }else if(tree->key == key){
    return true;
  }else if(tree->key > key){
    return findKey(tree->left, key);
  }else{
    return findKey(tree->right, key);
  }
}

int BST::height(TreeNode* tree)
{
  int heightLeft = 0;
  int heightRight = 0;
  if(tree->left != nullptr){
    heightLeft = height(tree->left);
  }
  if(tree->right != nullptr){
    heightRight = height(tree->right);
  }
  if(heightLeft > heightRight){
    return heightLeft+1;
  }else{
    return heightRight+1;
  }
}

void BST::postOrderTraversal(TreeNode* tree)
{
  if(tree == nullptr)
    return;
  postOrderTraversal(tree->left);
  postOrderTraversal(tree->right);
  cout << tree->key << " ";
}

int BST::countLeaves(TreeNode* tree)
{
  if(tree->left == nullptr && tree->right == nullptr){
    return 1;
  }else{
    return countLeaves(tree->left) + countLeaves(tree->right);
  }
}

int BST::countNodes(TreeNode* tree)
{
  if(tree->left != nullptr && tree->right != nullptr){
    return 1;
  }else{
    return countNodes(tree->left) + countNodes(tree->right);
  }
}

BST::TreeNode* BST::deleteNode(TreeNode* tree, int key)
{
  if(tree == nullptr){
    return tree;
  }else if(key < tree->key){
    tree->left = deleteNode(tree->left, key);
  }else if(key > tree->key){
    tree->right = deleteNode(tree->right, key);
  }else{
    if(tree->right == nullptr){
      TreeNode* temp = tree->left;
      delete tree;
      return temp;
    }else if(tree->left == nullptr){
      TreeNode* temp = tree->right;
      delete tree;
      return temp;
    }else{
      TreeNode* temp = minValue(tree->right);
      tree->key = temp->key;
      tree->right = deleteNode(tree->right, temp->key);
    }
  }
  return tree;
}

BST::TreeNode* BST::minValue(TreeNode* tree)
{
  TreeNode* temp = tree;
  while(temp && temp->left != nullptr){
    temp = temp->left;
  }
  return temp;
}



BST::BST()
{
  root = nullptr;
}

BST::BST(const BST &other)
{
  if(other.root == nullptr){
    root = nullptr;
  }else
    root = copyTree(other.root);
}

BST::~BST()
{
  destructor(root);
}

void BST::operator=(const BST &other)
{
  if(root != other.root){
    destructor(root);
    root = copyTree(other.root);
  }
}

bool BST::insert(int key)
{
  return insert(root, key);
}

bool BST::findKey(int key)
{
  return findKey(root, key);
}

int BST::height()
{
  if(root != nullptr){
    return height(root);
  }else{
    return 0;
  }
}

void BST::postOrderTraversal()
{
  postOrderTraversal(root);
}

void BST::inOrderTraversal()
{
  stack<TreeNode*> s;
  TreeNode* temp = root;
  while(temp != nullptr || !s.empty()){
    while(temp != nullptr){
      s.push(temp);
      temp = temp->left;
    }
    temp = s.top();
    s.pop();

    cout << temp->key << " ";

    temp = temp->right;
  }
}

int BST::countLeaves()
{
  if(root == nullptr){
    return 0;
  }else{
    return countLeaves(root);
  }
}

int BST::countNodes()
{
  if(root == nullptr){
    return 0;
  }else{
    return countNodes(root);
  }
}

void BST::deleteNode(int key)
{
  if(root == nullptr){
    return;
  }else{
    root = deleteNode(root, key);
  }
}