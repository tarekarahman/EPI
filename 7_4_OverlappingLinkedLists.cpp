#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// To execute C++, please define "int main()"

struct Node{
  int data;
  shared_ptr<Node> next;
};

  int Length(shared_ptr<Node> L0){
    int length = 0;
    while(L0){
      L0 = L0->next;
      length++;
    }
    return length;
  }

void advanceByK(int k, shared_ptr<Node>* L ){
  while(k--){
    *L = (*L)->next;
  }

}

shared_ptr<Node> testOverlapping(shared_ptr<Node> L1, shared_ptr<Node> L2){
 advanceByK(abs(Length(L1)-Length(L2)),( Length(L1)>Length(L2) ) ? &L1 : &L2  );
  
  while(L1 && L2 && (L1 != L2)){
    
    L1 = L1->next;
    L2 = L2->next;
  }
  return L1;
  

}
  

int main() {
  shared_ptr<Node> L1 = make_shared<Node>(Node{0,nullptr});
  shared_ptr<Node> L2 = make_shared<Node>(Node{1,nullptr});
  L2->next = make_shared<Node>(Node{2,nullptr});
  L2->next->next = make_shared<Node>(Node{3,nullptr});
  L1->next = L2;
  
  if(testOverlapping(L1,L2) != nullptr){
    cout<<"both linked lists overlap";
  }
  
  return 0;
}
