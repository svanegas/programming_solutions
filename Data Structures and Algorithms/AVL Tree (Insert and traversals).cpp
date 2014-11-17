//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct Node {
  int key;
  Node *left;
  Node *right;
  int height;
};

//Returns a pointer to a node with the key received and no childs (leaf)
Node*
createNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->height = 1;
  node->left = NULL;
  node->right = NULL;
}

int
getHeight(Node *node) {
  if (node == NULL) return 0;
  return node->height; 
}

//if the returned value is greater than 1 means that the node is unbalanced.
int
getBalance(Node *node) {
  return getHeight(node->left) - getHeight(node->right);
}

Node*
rightRotate(Node *node) {
  //Store subtrees
  Node *leftSubTree = node->left;
  Node *rightOfLeft = leftSubTree->right;
  
  //Perform rotation
  leftSubTree->right = node;
  node->left = rightOfLeft;
  
  //Update heights
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  leftSubTree->height = max(getHeight(leftSubTree->left),
                            getHeight(leftSubTree->right)) + 1;
  
  //return the new root
  return leftSubTree;
}

Node*
leftRotate(Node *node) {
  //Store subtrees
  Node *rightSubTree = node->right;
  Node *leftOfRight = rightSubTree->left;
  
  //Perform rotation
  rightSubTree->left = node;
  node->right = leftOfRight;
  
  //Update heights
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  rightSubTree->height = max(getHeight(rightSubTree->left),
                             getHeight(rightSubTree->right)) + 1;
  
  //return the new root
  return rightSubTree;
}

//node: root of the tree
//key: value to be inserted
Node*
insert(Node *node, int key) {
  if (node == NULL) {
    return createNode(key);
  }
  else if (key < node->key) {
    //I have to insert key in the left sub-tree
    node->left = insert(node->left, key); 
  }
  else {
    node->right = insert(node->right, key);
  }
  
  //update the parent's (node) height
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  
  int balanceFactor = getBalance(node);
  
  //Balance the tree
  if (balanceFactor > 1) {
    //Left left
    if (key < node->left->key) {
       return rightRotate(node);
    }
    //Left right
    else {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  else if (balanceFactor < - 1) { 
    //Right right
    if (key > node->right->key) {
      return leftRotate(node);
    }
    //Right left
    else {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

/*
Right right unbalance

     10                                 20
       \      Left rotation (10)       /  \
        20     ==============>        10  30
          \
          30
          
Left left unbalance

     10                               5
    /      Right rotation (10)       / \
   5         ==============>        3  10
  /       
 3     
 
Left right unbalance
     10                           10                          7
    /      Left rotation (5)     /   Right rotation (10)     / \
   5         ==============>    7     =================>    5  10
    \                          /
     7                        5

Right left unbalance
     10                         10                              12
       \    Right rotation (15)   \      Left rotation (10)     / \
       15    ==============>       12    =================>    10  15
       /                            \
     12                              15

*/

void
preorderTraversal(Node* node) {
  cout << node->key << endl;
  if (node->left != NULL) preorderTraversal(node->left);
  if (node->right != NULL) preorderTraversal(node->right); 
}

void
inorderTraversal(Node* node) {
  if (node->left != NULL) inorderTraversal(node->left);
  cout << node->key << endl;
  if (node->right != NULL) inorderTraversal(node->right); 
}

void
postorderTraversal(Node* node) {
  if (node->left != NULL) postorderTraversal(node->left);
  if (node->right != NULL) postorderTraversal(node->right); 
  cout << node->key << endl;
}
    
int
main() {
  Node *root = NULL;
  cout << "Enter nodes to insert or -1 to exit" << endl;
  int x;
  while (cin >> x && x != -1) {
    root = insert(root, x);
  }
  puts("\n PREORDER TRAVERSAL");
  preorderTraversal(root);
  puts("\n INORDER TRAVERSAL");
  inorderTraversal(root);
  puts("\n POSTORDER TRAVERSAL");
  postorderTraversal(root);
  return 0;
}
