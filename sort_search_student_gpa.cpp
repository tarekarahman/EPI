#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct student{
string name;
  double gpa;
};

// To execute C++, please define "int main()"
int main(){

  vector<int> x{1,6,2,3,2};
  // sort(x.begin(),x.end(),greater<>());
  // cout<<x[0];
  
  student s2{"hoda",3.5};
  student s1{"tarek",4.0};
  student s3{"obad",4.0};
  vector<student> students{s1,s2};
  sort(students.begin(),students.end(),[](const student s1,const student s2){
    if(s1.gpa==s2.gpa){
      return s1.name<s2.name;
    }
    else{
    return  s1.gpa>s2.gpa;

    }
  }
);

    bool isThere=binary_search(students.begin(),students.end(),s3,[]( student s1, student s2){
    if(s1.gpa==s2.gpa){
      return s1.name<s2.name;
    }
    else{
    return  s1.gpa>s2.gpa;

    }
  }
);
  cout<<s3.name<<" is registered = "<<isThere<<endl;
  
     cout<<"Sorted with respect to their GPA:"<<endl;
    for(auto s:students){
    cout<<s.name<<endl;
      cout<<s.gpa<<endl;
    }
    
   
  return 0;
}
