#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> A){
  //  99+1=
  // 100
  ++A.back();
  
  for(int i =A.size()-1;i>0; i--){
    if(A[i] == 10){
     A[i]=0;
      A[i-1]++;
    }
    
  }
  
  if(A[0]==10){
   A[0]=1;
   A.push_back(0);
  }
  return A;

}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  // vector<int> x{1,2,3};
  // vector<int> y(x.rbegin(),x.rend());
  // cout<<({x.rbegin(),x.rend()})[0];
  auto result = plusOne(vector<int>{9,9,9,9});
  for(auto it =result.begin();it!=result.end();++it){
    cout<<*it;
   }
  //cout<<endl;
  
  //cout<<plusOne(19)<<endl;
  return 0;
}
