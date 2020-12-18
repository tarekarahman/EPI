#include <iostream>
using namespace std;
#include <random>

int partition(vector<int>* A_ptr,int left, int right, int k);
int findKthLargest(int k,vector<int>* A_ptr){
  vector<int>& A=*A_ptr;
  int left=0; int right=A.size()-1;
  default_random_engine gen;
  while(left<=right){
    uniform_int_distribution dist(left,right);
    int pivot_idx = dist(gen);
    int new_pivot_idx=partition(A_ptr,left,right, pivot_idx);
   //cout<<new_pivot_idx<<endl;
    if(new_pivot_idx==k-1){
    return A[new_pivot_idx];
      }
    if(new_pivot_idx> (k-1)){
    right=new_pivot_idx-1;
      }
    else{
      left=new_pivot_idx+1;
    }

    }
  
}

int partition(vector<int>* A_ptr,int left, int right, int pivot_idx){
  vector<int>& A=*A_ptr;
  int pivotValue = A[pivot_idx];
  int newIdx=left;
  swap(A[pivot_idx],A[right]);
  
  for(int i = left;i<right;i++){
    if(A[i]>pivotValue){
      swap(A[i],A[newIdx++]);
    }
  }
  swap(A[right],A[newIdx]);
  return newIdx;
}

// To execute C++, please define "int main()"
int main() {
  vector<int> A{3,1,-1,2};
  //vector<int> A{3,2,1,5,4};
  vector<int>* A_ptr = &A;
  auto res=findKthLargest(2,A_ptr);
  cout<<res;
  return 0;
}
