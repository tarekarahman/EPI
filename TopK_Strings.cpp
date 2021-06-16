#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;


vector<string> Topk(int k, vector<string>::const_iterator stream_begin,  const vector<string>::const_iterator &stream_end){
  
  priority_queue<string,vector<string>,function<bool(string,string)>> 
    min_heap([](const string& a, const string& b){
  
    return a.size()>=b.size();
  
  }
                                                                               
      );
  while(stream_begin != stream_end){
    min_heap.push(*stream_begin);
    
    if(min_heap.size() == k+1){
    min_heap.pop();
    
    }
    
  stream_begin = next(stream_begin);
    }
  
  vector<string> result;
  while(!min_heap.empty()){
    auto top = min_heap.top();
    result.push_back(top);
    min_heap.pop();
  }
  return result;
    
    }


// To execute C++, please define "int main()"
int main() {
vector<string> s;
s.push_back("hii");
s.push_back("hiii");
s.push_back("hiiii");
s.push_back("hiiiii");
s.push_back("hiiiiii");
s.push_back("hiiiiiii");
s.push_back("hiiiiiiii");
  
  vector<string> result = Topk(6,s.begin(),s.end());
for(auto it =result.begin();it!=result.end();++it){
    cout<<*it<<" ";
    }  
  return 0;
}
