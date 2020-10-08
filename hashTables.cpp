#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <numeric>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<vector<string>> findAnagrams(const vector<string>& words){
unordered_map<string,vector<string>> sortedAnagram;
  
  // creating the hashtable
for(const auto& s: words){
string sorted_string(s);
sort(sorted_string.begin(),sorted_string.end());
sortedAnagram[sorted_string].push_back(s);
}
  vector<vector<string>> anagramGroup;
  
  for (const auto& [key,values]: sortedAnagram){
    if(values.size() >= 2){
    anagramGroup.push_back(values);
    }
  }
return anagramGroup;
}

int stringHash(const string &s, int modulus){
int kmult = 997;
auto hashCode= accumulate(s.begin(),s.end(),0,[kmult,modulus](int value, char c){
return (value*kmult + c) % modulus;
});
  return hashCode;
}

int StringHash(const string &s, int modulus){
int kmult = 997;
int value=0;
for(char c: s){
value=(value*kmult+c) % modulus;
}
  return value;
}

// To execute C++, please define "int main()"
int main() {
  vector<string> words = { "debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis"
                          , "money"};
  auto anagrams = findAnagrams(words);
  //cout<<anagrams.size()<<endl;
  assert(anagrams.size() == 3);
  // auto anagrams = findAnagrams(words);
  int i=0;
  for (auto group : anagrams) {
    i++;
    cout<< "Anagram number "<<i<<endl;
    for (auto s : group){
    cout << s<<" ";
    }
    cout<<endl;
  }
  return 0;
}


//
// 
