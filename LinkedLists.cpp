// Example program
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <cassert>
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

void appendN(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> tail){
    tail->next =L;
    tail=L;
    L=L->next;
    cout<<"it entered appendN";
    }
    
    
shared_ptr<ListNode<int>> mergeN(const shared_ptr<ListNode<int>>& L1,  const shared_ptr<ListNode<int>>& L2){
   // shared_ptr<ListNode<int>> res = make_shared<ListNode<int>>();
        shared_ptr<ListNode<int>> res (new ListNode<int>);

    auto tail=res;
    while(L1 && L2){
        
        if(L1->data <= L2->data)
            appendN(L1,tail);
        else
            appendN(L2,tail);
        }
        tail->next = L1 ? L1 : L2;
        cout<<"it entered end of N";
    return res->next;
    }




int main()
{
  shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{
      2,make_shared<ListNode<int>>(ListNode<int>{
          5, make_shared<ListNode<int>>(ListNode<int>{
              7, nullptr
              })
          })
      });
      
        shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{
      3,make_shared<ListNode<int>>(ListNode<int>{
              11, nullptr
          })
      });
      
      int key =2;
      
    //   shared_ptr<ListNode<int>> L2;
    //   L2=searchList(L,key);
  //DeletionFromList(L);
  
  shared_ptr<ListNode<int>> L12;
  L12= mergeN(L1,L2);
  
  //assert(L12->next-> data == 3 && L12->next->next->data == 5);
  cout<<"all is well";
  return 0;

}

