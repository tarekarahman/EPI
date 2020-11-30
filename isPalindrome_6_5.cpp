#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
bool isPalindrome(const string& s);
int main() {
auto words = { "Ray a Ray", "A man, a plan, a canal, Panama","Able was I, ere I saw Elba!"};
  for (const string& word : words) {
    cout << word<<" "<< isPalindrome(word)<<endl;
  }
  //cout<<! islower('a');
  return 0;
}

bool isPalindrome(const string& sTest){
  string s = sTest;
  size_t i=0;size_t j=s.size()-1;
  
  while(i<j){
    if(!isalnum(s[i])){
      i++;
      continue;
    }
    
   if(!isalnum(s[j])){
      j--;
     continue;
    } 
    if(!islower(s[i])){
     // i++;
      s[i]=tolower(s[i]);
    }
    
   if(!islower(s[j])){
      //j--;
     s[j]=tolower(s[j]);
    }     
    
    
    if(s[i] != s[j]){
      return false;
    }
    i++;
    j--;
  }
  return true;
}
