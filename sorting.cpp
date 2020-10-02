#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <cassert>
#include <stack>
#include <stdexcept>
//#include <list>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;



struct Student{
    bool operator<(const Student& that)  {
        return name<that.name;
        }
    string name;
    double gpa;
    };
    


void sortbyGPA(vector<Student>*& students){
    sort(students->begin(),students->end(),[](const Student& a,const Student& b ){
        return a.gpa >= b.gpa;
        });
    }
    
                  void sortbyName(vector<Student>*& students){
        sort(students->begin(),students->end());
        }
    
    
vector<int> intersect(const vector<int>& A, const vector<int>& B){
    vector<int> result;
    for(int i =0;i<A.size();i++){
        if((i==0 || A[i] != A[i-1]) && binary_search(B.begin(),B.end(),A[i]) ){
            result.push_back(A[i]);
            }
        }
    
    return result;
    }
    
        
vector<int> intersectEfficient(const vector<int>& A, const vector<int>& B){
    vector<int> result;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        if((i==0 || A[i] != A[i-1]) && A[i] == B[j]){
            result.push_back(A[i]);
            j++;
            }
            i++;
            if((j==0 || B[j] != B[j-1]) && A[i] == B[j]){
            result.push_back(A[i]);
            i++;
            }
            j++;
            
            
        }
    
    return result;
    }

int main()
{


vector<int> A={2,3,3,5,5,6,7,7,8,12};
vector<int> A1={2,3,3,5,7,11};
vector<int> B={5,5,6,8,8,9,10,10};
vector<int> B1={3,3,7,15,31};


//cout<<bsearchFirstOccur(A,285)<<endl;


  //Traverse(tree);
  
//   Student studenta{"Tarek",4.0};
//   Student studentc{"Manar",3.99};
//     Student studentd{"Hoda",3.5};
//   Student studentb{"Obad",3.3};
  
//   vector<Student> students{studenta,studentb,studentc,studentd};
  
//   vector<Student>* student_ptr;
//   student_ptr=&students;
  
//   sortbyGPA(student_ptr);
  
//   for(auto it = students.begin();it!= students.end();++it){
//       cout<<it->name<<" "<<it->gpa<<endl;
//       }
  
//   //assert(searchStudent(students,Student{"Obad",3.3},compGPA));


auto result= intersect(A,B); //O(m log(n))
     for(auto it = result.begin();it!= result.end();++it){
      cout<<' '<<*it;
      }
      cout<<endl;
  auto result1= intersectEfficient(A1,B1); //O(m+n)
     for(auto it = result1.begin();it!= result1.end();++it){
      cout<<' '<<*it;
      }
      cout<<endl;    
      
    cout<<"all is well"<<endl;

  
  return 0;

}
