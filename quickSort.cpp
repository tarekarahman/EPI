#include <iostream>
using namespace std;
#include <random>


void bubbleSort(vector<int>* A_ptr){
  vector<int>& A =*A_ptr;
  for(size_t i =0;i<A.size()-1;i++){
    for(size_t j =0;j<A.size()-1-i;j++){
      if(A[j]>A[j+1]){
        swap(A[j],A[j+1]);
      }
    }
  }
}


int partition(vector<int>* A_ptr,int left,int right){
     vector<int>& A =*A_ptr;
     int pivotIdx=right;
     int pivotValue = A[pivotIdx];
     int newPivotIdx=left;
      for(int i = left;i<right;i++){
        if(A[i]<pivotValue){
          swap(A[i],A[newPivotIdx++]);
        }
        
      }
    swap(A[newPivotIdx],A[right]);
  return newPivotIdx;
}



void quickSortHelper(vector<int>* A_ptr,int left,int right){
  int new_pivot_idx;
      if(left<=right){
         new_pivot_idx= partition(A_ptr,left,right);
        quickSortHelper( A_ptr,left,new_pivot_idx-1);
        quickSortHelper( A_ptr,new_pivot_idx+1,right);
      }
}


void quickSort(vector<int>* A_ptr){
  quickSortHelper( A_ptr,0,(*A_ptr).size()-1);

  
  
}

// To execute C++, please define "int main()"
int main() {
  vector<int> A{21, 4, 1, 3, 9, 20, 25, 6, 21, 14,-1};
  //vector<int> A{3,2,1,5,4};
  vector<int>* A_ptr = &A;
  quickSort(A_ptr);
  for(auto it = A.begin();it !=A.end();++it){
    cout<<*it<<endl;
  }
  cout<<endl;
  return 0;
}
