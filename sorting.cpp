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
                                    
                                    
      

int main()
{


vector<int> A={-14,-10,2,108,108,243,285,285,285,401};

//cout<<bsearchFirstOccur(A,285)<<endl;


  //Traverse(tree);
  
  Student studenta{"Tarek",4.0};
  Student studentc{"Manar",3.99};
    Student studentd{"Hoda",3.5};
  Student studentb{"Obad",3.3};
  
  vector<Student> students{studenta,studentb,studentc,studentd};
  
  vector<Student>* student_ptr;
  student_ptr=&students;
  
  sortbyGPA(student_ptr);
  
  for(auto it = students.begin();it!= students.end();++it){
      cout<<it->name<<" "<<it->gpa<<endl;
      }
  
  //assert(searchStudent(students,Student{"Obad",3.3},compGPA));
  
    cout<<"all is well"<<endl;

  
  return 0;

}
