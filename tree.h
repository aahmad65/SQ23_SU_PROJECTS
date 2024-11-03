//Aidan Ahmad
//tree.h
//Header file for a binary search tree

#include<iostream>
#include<iomanip>
#include<stack>


class BST
{
  private:
  class TreeNode
  {
    public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
      left = nullptr;
      right = nullptr;
    }
  };
  TreeNode* root;

  TreeNode* copyTree(const TreeNode* other);

  bool insert(TreeNode*& tree, int key);

  void destructor(TreeNode*& tree);

  bool findKey(TreeNode* tree, int key);

  int height(TreeNode* tree);

  void postOrderTraversal(TreeNode* tree);
  
  int countLeaves(TreeNode* tree);

  int countNodes(TreeNode* tree);

  TreeNode* deleteNode(TreeNode* tree, int key);

  TreeNode* minValue(TreeNode* tree);

  
  
  public:
  
  BST();

  BST(const BST &other);

  ~BST();

  void operator=(const BST &other);

  bool insert(int key);

  bool findKey(int key);

  int height();

  void postOrderTraversal();

  void inOrderTraversal();

  int countLeaves();

  int countNodes();
  
  void deleteNode(int key);
};
