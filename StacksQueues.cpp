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
int main()
{
  Stack s;
  s.Push(1);
  s.Push(2);
  assert(s.Max() == 2);
  cout << s.Max() << endl;  // 2
  cout << s.Pop() << endl;  // 2
  assert(s.Max() == 1);
  cout << s.Max() << endl;  // 1
  s.Push(3);
  s.Push(2);
  assert(s.Max() == 3);
  cout << s.Max() << endl;  // 3
  s.Pop();
  assert(s.Max() == 3);
  cout << s.Max() << endl;  // 3
  s.Pop();
  assert(s.Max() == 1);
  cout << s.Max() << endl;  // 1
  s.Pop();

  cout<<"all is well";
  return 0;

}

