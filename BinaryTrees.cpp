// Example program
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <cassert>
#include <stack>
#include <stdexcept>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
    };
    
    shared_ptr<ListNode<int>> searchList(shared_ptr<ListNode<int>> L, int key){
        while(L && L->data != key ){
            L=L->next;
            }
            return L;
        }
    
void insertAfter(const shared_ptr<ListNode<int>>& L, const  shared_ptr<ListNode<int>>& L1){
    L1->next=L->next;
    L->next=L1;
    
    }
    
    void deleteAfter(const shared_ptr<ListNode<int>>& L){
    
    L->next=L->next->next;
    
    }

void PrintLinkedListInReverse(shared_ptr<ListNode<int>> head){
    stack<int> nodes;
    while(head)
    {nodes.push(head->data);
    head = head->next;
        }
        while(!nodes.empty()){
            cout<<nodes.top();
            nodes.pop();
            }
    
    }

class Stack{
    public:
    bool Empty(){
        return _valueStruc.empty();
        }
    int Max(){
        return _valueStruc.top().max;
        }
        int Pop(){
            int e =  _valueStruc.top().element;
            _valueStruc.pop();
            return e;
            
            }
        void Push(int e){
            _valueStruc.push(ValueStruc{e, _valueStruc.empty() ?  e : max(e,_valueStruc.top().max ) });
            
            }
    private:
    struct ValueStruc{
        int element,max;
        };
        stack<ValueStruc> _valueStruc;
    
    };
    
    class Queue{
        public:
        void enqueue(int x){
            _data.push_back(x);
            }
        int dequeue(){
            int f= _data.front();
            _data.pop_front();
            return f;
            }
            int Max(){return *max_element(_data.begin(),_data.end());}
        
        private:
        list<int> _data;
        
        };
        
    template <typename T>
    struct BinaryTreeNode{
        T data;
        unique_ptr<BinaryTreeNode<T>> left,right;
        };
        
       
       void Traverse(const unique_ptr<BinaryTreeNode<int>>& root){
           if(root){
           cout<<"Preorder "<<root->data << endl;
           Traverse(root->left);
           cout<<"Inorder "<<root->data << endl;
            Traverse(root->right);
           cout<<"Postorder "<<root->data << endl;
           }
         
           } 
           
           struct BalancedTreeNode{
               bool balanced;
               int height;
               };
               
                                  BalancedTreeNode checkBalanced(const unique_ptr<BinaryTreeNode<int>>& tree){
                       if (tree== nullptr){
                           return {true, -1};
                           }
                           
                      auto balancedLeft=checkBalanced(tree->left);
                       auto balancedRight= checkBalanced(tree->right);
                       if(! balancedLeft.balanced){
                           return { false, 0};
                           }
                           
                      if(! balancedRight.balanced){
                           return { false, 0};
                           }
                      

                       auto height= max(balancedLeft.height,balancedRight.height)+1;
                       auto balance = (abs(balancedLeft.height-balancedRight.height)<=1);
                       return {balance, height};
                       }
                       
               bool isBalanced(const unique_ptr<BinaryTreeNode<int>>& tree ){
                   return checkBalanced(tree).balanced;
                   }

int main()
{

  //      3
  //    2    5
  //  1     4 6
  // 2
  
  auto tree = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{3, nullptr, nullptr});
  tree->left = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{2, nullptr, nullptr});
  tree->left->left = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{1, nullptr, nullptr});
        tree->left->left->left = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{2, nullptr, nullptr});
    //  tree->left->left->left->left = make_unique<BinaryTreeNode<int>>(
    //   BinaryTreeNode<int>{3, nullptr, nullptr});
  tree->right = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{5, nullptr, nullptr});
  tree->right->left = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{4, nullptr, nullptr});
  tree->right->right = make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int>{6, nullptr, nullptr});
  cout<<"all is well";
  //Traverse(tree);
  cout<<isBalanced(tree);
  return 0;

}

