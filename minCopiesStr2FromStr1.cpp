#include <iostream>
using namespace std;
#include <string>
#include <queue>

// calulcate minimum number of copies for string 1 to form string 2 
// string 1 = ABCD, string 2 = DAD, return: 2

int calculateCopies(string string1, string string2) {
    int res=0;
    bool flag = false;
    queue<char> qRef,qCurr;
    for(auto c:string1){
    qRef.push(c);
    }
    qCurr=qRef;
  
    
  for(size_t i =0;i<string2.size();i++){
    char c2 = string2[i];
    char c1;
    while(!qCurr.empty()){
      c1 = qCurr.front();
      cout<<c2<<" "<<c1<<endl;
      qCurr.pop();
      if(c1 == c2){
       flag = true;
      }
      if(flag && qCurr.empty() ){
        res++;
        cout<<"Result incremented and now is"<<res<<endl;
        qCurr=qRef;
        flag = false;
        if(c1!=c2){
        i--;
        }
        break;
      }
      // else if(flag && i ==string2.size()-1  ){
      //   if(c1 ==c2){
      //   res++;
      //   cout<<"Result incremented and now is"<<res<<endl;
      //   }
      // }      
      else if(c1 == c2){
        if(i== string2.size()-1){res++;}
        break;
      }
    }
    
    
  }

 cout<<"final result is "<<res<<endl;
 cout<<endl; 
 return res;
}

// To execute C++, please define "int main()"
int main() {
  string string1={"ABCD"};
  string string2 = {"DAD"};
  string string3={"CAB"};
  
  calculateCopies(string1 ,string2); // 2
  calculateCopies(string3 ,string2); // 0
  calculateCopies(string1 ,string3); // 2
  calculateCopies(string2 ,string2); // 1
  

  
  // for (const string& word : words) {
  //   cout << word;
  // }
  return 0;
}

