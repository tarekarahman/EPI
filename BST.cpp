#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <limits> 
using namespace std;

template <typename T> 
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left,right;
    };
    
    BSTNode<int>* SearchBST(const unique_ptr<BSTNode<int>>& tree, int key){
        if(tree == nullptr){
            return nullptr;
            }
            return tree->data == key ? tree.get() : 
                                key < tree->data  ? SearchBST(tree->left,key) : SearchBST(tree->right,key);
            
        }
        
      bool range(const unique_ptr<BSTNode<int>>& tree, int lB, int uB){
        if(tree == nullptr){
            return true;
            }
            else if(tree->data<lB || tree->data>uB){
                return false;
                } 
                else{
                    return range(tree->left, lB,tree->data) && range(tree->right,tree->data, uB);
                    }
        }       
        bool isTreeBST(const unique_ptr<BSTNode<int>>& tree){
              return range(tree,numeric_limits<int>::min(),numeric_limits<int>::max()) ;
            }

int main()
{
 unique_ptr<BSTNode<int>> tree1=(make_unique<BSTNode<int>>(
     BSTNode<int>{50, nullptr,nullptr}));
 tree1->left=make_unique<BSTNode<int>>(
     BSTNode<int>{25, nullptr,nullptr});
tree1->right=make_unique<BSTNode<int>>(
     BSTNode<int>{75, nullptr,nullptr});
     int key =50;
     auto node = SearchBST(tree1,key);
    assert(50 == node->data);
    
   auto tree = make_unique<BSTNode<int>>(BSTNode<int>{3});
  tree->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
  tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
  tree->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
  tree->right->left =
      make_unique<BSTNode<int>>(BSTNode<int>{4});
  tree->right->right =
      make_unique<BSTNode<int>>(BSTNode<int>{6});
  // should output true.
  assert(isTreeBST(tree) == true);
  cout << "Hello";
  return 0;
}



