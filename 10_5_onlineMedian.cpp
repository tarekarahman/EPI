#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"

vector<double> OnlineMedian(vector<int>::const_iterator beg, const vector<int>::const_iterator& end){
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<>> min_heap;
  vector<double> result;
  while(beg!=end){
    min_heap.push(*beg++);
    max_heap.push(min_heap.top());
    min_heap.pop();
    if(max_heap.size() > min_heap.size() ){
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
   result.push_back( min_heap.size()>max_heap.size() ? min_heap.top() 
                                                       : 0.5 * (min_heap.top() + max_heap.top())   );   
  }
  return result;
}
  

int main() {
  vector<int> stream{1,0,3,5,2,0,1};
  auto result = OnlineMedian(stream.begin(),stream.end());
  
  for (const auto& e: result) {
    cout << e<<' ';
  }
  return 0;
}

