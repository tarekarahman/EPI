// Example program
#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <limits> 
#include <queue> 
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
            
    //         struct QueueEntry{
    //             const unique_ptr<BSTNode<int>>& tree;
    //             int lB,uB;
                
    //         };
    // bool isTreeBSTQueue(const unique_ptr<BSTNode<int>>& t){
    //     queue<QueueEntry> q;
    //     q.emplace(QueueEntry{t,numeric_limits<int>::min(),numeric_limits<int>::max()});
    //     while(!q.empty()){
    //         if(q.front().tree.get()==nullptr){
    //             return true;
    //             }
    //         else if(q.front().tree->data<q.front().lB || q.front().tree->data>q.front().uB){
    //             return false;
    //             } 
    //           q.emplace(QueueEntry{q.front());
               
    //         q.pop();
    //         }
    //     return true;
    // }
////////////////////////////////////32
//                            15             64
//                                       40      80  
    BSTNode<int>* findLargerK(const unique_ptr<BSTNode<int>>& tree, int key){
        BSTNode<int>* result = nullptr;
        auto current_node = tree.get(); 
        while(current_node != nullptr){
        if(current_node->data > key){
            result=current_node;
            current_node=current_node->left.get();
            }
            else if (current_node->data <= key){
                current_node=current_node->right.get();
                }
        }
        return result;
        
        }
        
                void BSTHelper(const unique_ptr<BSTNode<int>>& tree, vector<int>& result,int k){ 
            if(tree != nullptr && result.size()<k){
                BSTHelper(tree->right,result,k);
            }
            
            if(tree != nullptr && result.size()<k){
                result.push_back(tree->data);
                BSTHelper(tree->left,result,k);
                }

            
            }
            vector<int> findKLargestBST(const unique_ptr<BSTNode<int>>& tree, int k){
           vector<int> result;
           BSTHelper( tree,  result, k);
           return result;

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
  
//  auto res=findLargerK(tree,3);
//   cout<<res->data<<endl;
//  assert(res->data == 4);
 
 vector<int> result;
 int k =6;
 result= findKLargestBST(tree,k);
 for(auto it = result.begin(); it!=result.end();++it){
     cout<<*it<<endl;
     }
  cout << "Hello";
  return 0;
}



