#include <iostream>

using namespace std;



long long reverseInt(int x){
  bool isNegative = false;
  long long result=0;
  if(x<0){
    isNegative = true;
    x = x*-1;
  }
  
  while(x){
    result = result*10 + (x % 10);
    x=x/10;
      
  }
  
  
  
  return isNegative ? -1*result : result;
  

}



// To execute C++, please define "int main()"
int main() {

  int x = 423;
 cout<<reverseInt(x);
  
  
}
