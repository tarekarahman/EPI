#include <iostream>
#include <stack>
using namespace std;


/*
Alice likes Bob -> Bob likes Alice



*/
void reverseWords(string* s){
string& S = *s;
  string currWord;
  stack<string> reverseStack;
  if(S.empty()){
    return;
  }
  for(size_t i=0;i<S.size();i++ ){
    char c = S[i];
    if(c == ' ' ){
      if(!currWord.empty() ){
        reverseStack.push(currWord);
        currWord.clear();
      }
    }
    else{
      currWord+=c;
    }
      if(i== S.size()-1){
    reverseStack.push(currWord);
  }
  }

  S.clear();
  while(!reverseStack.empty()){
    //cout<<reverseStack.top()<<endl;
    S+=reverseStack.top();
    reverseStack.pop();
    if(!reverseStack.empty()){
      S+=" ";
    }
  }
  
}

// To execute C++, please define "int main()"
int main() {
  string word = { "Alice likes Bob"};
  string* wordPtr = &word;
  reverseWords(wordPtr);
  for (const auto& c : *wordPtr) {
    cout << c;
  }
  return 0;
}
