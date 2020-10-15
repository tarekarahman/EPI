#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;




int circularSorted(const vector<int>& nums){
int left=0;
int right=nums.size()-1;
int M = left + (right - left)/2;
while(left<right){
if( M = left + (right - left)/2; nums[M]>nums[right]){
left=M+1;
}
  else{
  right=M;
  }

}
  
  return right; 
}




int main() {
  vector<int> A1 = { 3,4,7,1,2};
  vector<int> A2 = { 4,7,1,2,3};
  vector<int> A3 = { 378,478,550,631,103,203,220,234,279,368};


  cout<<circularSorted(A1)<<endl;
  cout<<circularSorted(A2)<<endl;
  cout<<circularSorted(A3)<<endl;

  
  return 0;
}


