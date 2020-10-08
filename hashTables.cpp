#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <numeric>
#include <unordered_map>
#include <cassert>
#include <numeric>

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

bool isLetterConstFromMagazine(const string& letter, const string& mag){
unordered_map<char, int> hashTable;
  for (const char&c: letter){
  ++hashTable[c];
  }
  for (const char&c: mag){
    auto it = hashTable.find(c);
    if(it!= hashTable.end()){
      --hashTable[c];
    }
    if(it== hashTable.end()){
    hashTable.erase(it);
    if(hashTable.size()==0){
      break;
    }
    }

  }
  return hashTable.empty();
}

int findNearestRepitition(const vector<string>& paragraph){
unordered_map<string,int> hashTable;
  int i=0;
  int nearestOcc=numeric_limits<int>::max();
for(const auto& word: paragraph){
  if(auto itClosest = hashTable.find(word); itClosest != hashTable.end()){
      nearestOcc = min(i-itClosest->second, nearestOcc);
  }
    //hashTable.insert({word, i });
  hashTable[word]=i;
      i++;

}  
  return nearestOcc != numeric_limits<int>::max()? nearestOcc: -1;

}

void SimpleTest() {
  assert(!isLetterConstFromMagazine("123", "456"));
  assert(!isLetterConstFromMagazine("123", "12222222"));
  assert(isLetterConstFromMagazine("123", "1123"));
  assert(isLetterConstFromMagazine("123", "123"));
  assert(!isLetterConstFromMagazine("12323", "123"));
  assert(
      isLetterConstFromMagazine("GATTACA", "A AD FS GA T ACA TTT"));
  assert(!isLetterConstFromMagazine("a", ""));
  assert(isLetterConstFromMagazine("aa", "aa"));
  assert(isLetterConstFromMagazine("aa", "aaa"));
  assert(isLetterConstFromMagazine("", "123"));
  assert(isLetterConstFromMagazine("", ""));
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
  
  vector<string> paragraph{"All", "work", "and", "no", "play", "makes", "for", "no", "work", "no"};
  cout<<findNearestRepitition(paragraph)<<endl;
  assert(findNearestRepitition(paragraph)==2);
  
  return 0;
}


//
// 
