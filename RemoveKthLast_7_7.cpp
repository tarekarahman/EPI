#include <iostream>
#include <memory>
using namespace std;



struct ListNode{
 int data;
 shared_ptr<ListNode> next;
};

shared_ptr<ListNode> removeKthLast(shared_ptr<ListNode> L, int k ){
  shared_ptr<ListNode> head = make_shared<ListNode>(ListNode{0,L});
  auto prev = head;
  auto curr = head->next;
  auto kcurr = curr;
  
  while(k--){
  kcurr = kcurr->next;
  }
  
  while(kcurr){
    kcurr = kcurr->next;
    prev = prev->next;
  }
  //curr is at the K+1 node from the last and kcurr is at the tail
  // remove k node from the last
  prev->next = prev->next->next;
  
  
 return head->next;

} 




// To execute C++, please define "int main()"
int main() {

  shared_ptr<ListNode> L = make_shared<ListNode>(ListNode{1,nullptr});
  L->next = make_shared<ListNode>(ListNode{2,nullptr});
  L->next->next = make_shared<ListNode>(ListNode{3,nullptr});
  L->next->next->next = make_shared<ListNode>(ListNode{4,nullptr});
  L->next->next->next->next = make_shared<ListNode>(ListNode{5,nullptr});
  
  auto L2 = removeKthLast(L, 5 );
  
  while(L2){
  cout<<L2->data<<endl;
  L2= L2->next;
  
  }
  
  return 0;
  
  
  
}
