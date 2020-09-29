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
#include <queue>
#include <cmath>

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

vector<string> Topk(int k, vector<string>::const_iterator stream_begin,  const vector<string>::const_iterator &stream_end){
    priority_queue<string,vector<string>,function<bool(string,string)>>
    min_heap([](const string &a, const string &b){
        return a.size()>b.size();
        });
        
        while(stream_begin!= stream_end){
            min_heap.push(*stream_begin);
            if(min_heap.size()>k){
                min_heap.pop();
                }
                stream_begin=next(stream_begin);
            }
            vector<string> result;
            while(! (min_heap.empty())){
                result.push_back(min_heap.top());
                min_heap.pop();
                }
            return result;
    }
    
    struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd& that)  {
    return *current > *that.current;
  }

  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>,
                 greater<>>
      min_heap;

  for (const vector<int>& sorted_array : sorted_arrays) {
    if (!sorted_array.empty()) {
      min_heap.emplace(
          IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()});
    }
  }

  vector<int> result;
  while (!min_heap.empty()) {
    auto smallest_array = min_heap.top();
    min_heap.pop();
    result.emplace_back(*smallest_array.current);
    if (next(smallest_array.current) != smallest_array.end) {
      
      min_heap.emplace(IteratorCurrentAndEnd{next(smallest_array.current),
                                             smallest_array.end});
    }
  }
  return result;
}
    // struct currentEnd{
    //     bool operator>(const currentEnd& that)const {
    //         return *current>*that.current;
    //         }  
    //     vector<int>::const_iterator current;
    //     vector<int>::const_iterator end;
    //     };
            struct currentEnd {
  bool operator>(const currentEnd& that)  {
    return *current > *that.current;
  }

  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};
        // @include

        
    vector<int> mergeSortedArrays(const vector<vector<int>>& sorted_arrays){
           priority_queue<currentEnd,vector<currentEnd>, greater<>>
           minHeap;
            // for(const auto sorted_array: sorted_arrays){
            //     if(! sorted_array.empty()){
            //     minHeap.push(currentEnd{sorted_array.cbegin(),sorted_array.cend()});
            //     }
            //      }
                 
                   for (const vector<int>& sorted_array : sorted_arrays) {
    if (!sorted_array.empty()) {
      minHeap.push(
          currentEnd{sorted_array.cbegin(), sorted_array.cend()});
    }
  }
            vector<int> result;
            
            while( ! minHeap.empty()){
            auto smallest1 = minHeap.top();
            minHeap.pop();
            //result.push_back(*smallest.current);
            if(smallest1.current != smallest1.end){
                result.push_back(*smallest1.current);
            //   smallest.current= next(smallest.current);
            //   minHeap.push(smallest);
              minHeap.push(currentEnd{next(smallest1.current),smallest1.end});
                }
            }
            return result;
       
            }
            
        struct Star{
            bool operator<(const Star& that)const {
                return Distance() < that.Distance();
                }
            
            double Distance()const{
                return sqrt(x*x+y*y+z*z);
            }
            double x,y,z;
            };    
            
            vector<Star> largestK(int k, vector<Star>::const_iterator iter_begin, vector<Star>::const_iterator iter_end){
                priority_queue<Star> max_heap;
                for(auto it = iter_begin;it!=iter_end;++it){
                    max_heap.push(*iter_begin);
                    while(max_heap.size() > k+1){
                        max_heap.pop();
                        }
                    }
                    vector<Star> result;
                    while( ! max_heap.empty()){
                        result.push_back(max_heap.top());
                        max_heap.pop();
                        }
                
                
                return result;
                }

int main()
{
// vector<string> s;
// s.push_back("hii");
// s.push_back("hiii");
// s.push_back("hiiii");
// s.push_back("hiiiii");
// s.push_back("hiiiiii");
// s.push_back("hiiiiiii");
// s.push_back("hiiiiiiii");

// auto stream_begin=s.begin();
// auto stream_end=s.end();
// int k=5;
vector<int> array1{3,5,7};
vector<int> array2{0,6};
vector<int> array3{0,6,8};

vector<vector<int>> sorted_arrays{array1,array2,array3};
//vector<int> result{{3,5,7},{0,6},{0,6,28}};

auto result =mergeSortedArrays(sorted_arrays);
//   int myints[] = {16,2,77,29};
//   std::vector<int> result (myints, myints + sizeof(myints) / sizeof(int) );
//   vector<vector<int>>
  
for(auto it =result.begin();it!=result.end();++it){
    cout<<*it;
    }



  cout<<"all is well";
  //Traverse(tree);
  return 0;

}

