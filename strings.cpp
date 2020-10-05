// Example program
#include <iostream>
#include <string>
#include <numeric>
using namespace std;


bool isPalindromic(string s){
    //bool res=false;
    int sSize=s.size();
    for(int i=0, j= sSize-1; i<j;i++,j--){
        if(s[i]!=s[j]){
            return false;
            }
        }
        return true;
      
    
    }
    
    string intToString(int x){
        string s;
        bool isNegative = false;
        if(x<0){
         isNegative =true;
            }
            
        while(x){
        s+='0'+ abs(x % 10);
        x=x/10;
        }
        s+= isNegative ? "-":"";
        return {s.rbegin(),s.rend()};
        }
        
    int stringToInt(string s){
         int x;
         bool isNegative = false;
         if(s[0]=='-'){
             isNegative = true;
             }
             
             // x = s_n-1 *10^0+ s_n-2*10^1..+s[0]*10^(n-1)
         x=accumulate(s.begin()+ isNegative, s.end(), 0, [](int sum, char c){
             return sum*10 + c - '0';
             });
        // x=x/10;
        return isNegative? x*-1 : x;
        }
                    int stringToInt(string s, int baseFrom){
                 int x;
                 bool isNegative = false;
                 if(s[0]=='-'){
                     isNegative = true;
                     }
                     
                 x=accumulate(s.begin()+ isNegative, s.end(), 0, [&baseFrom](int sum, char c){
                     return sum*baseFrom + (isdigit(c) ? c - '0' : c - 'A' + 10);
                     });
                return isNegative? x*-1 : x;
                }
                
            string intToString(int x, int baseTo){
                string s;
                bool isNegative = false;
                if(x<0){
                 isNegative =true;
                    }
                    
                while(x){
                s+= abs(x % baseTo)+ (abs(x % baseTo) >= 10 ? 'A'-10 : '0') ;
                x=x/baseTo;
                }
                s+= isNegative ? "-":"";
                return {s.rbegin(),s.rend()};
                }
        string convertBase(const string& s, int baseFrom, int baseTo){
            
            // int stringToInt(string s, int baseFrom);
            // string intToString(int x, int baseTo);
            
            auto x = stringToInt(s, baseFrom);
            cout<<"x is "<< x <<endl;
            
            return intToString(x, baseTo);
            

            
            }
            
            int replaceRemove(int size, char s[]){
                int writeIdx = 0, nAs =0;
                for(int i =0;i<size;i++){
                    if(s[i] != 'b'){
                        s[writeIdx++]=s[i];
                        }
                    if(s[i] == 'a'){
                        nAs++;
                        }
                    }
                auto currentIdx = writeIdx-1;
                writeIdx=currentIdx+nAs;
                const int finalSize=writeIdx+1;
                while(writeIdx >= 0 && currentIdx>=0){

                    if(s[currentIdx] == 'a'){
                        s[writeIdx--]='d';
                        s[writeIdx--] = 'd';
                        }
                    else{
                        s[writeIdx--]=s[currentIdx];
                        }
                        currentIdx--;
                    }
                return finalSize;
                }
    
int main()
{
string s = "helolehi";
cout<<"this string is palindromic "<< isPalindromic(s)<<endl;
int x = -423;

auto s1=intToString(x);
cout<<s1<<endl;

auto x1 = stringToInt(s1);
cout<<s1<<endl;


string sReverse{s.rbegin(),s.rend()};
cout<<sReverse<<endl;

int b1=7, b2=13;
string s3= "615";
cout<< convertBase(s3,b1,b2)<<endl;

char s4[]={'a','c','d','b','b','c','a'};
auto size = (sizeof(s4) / sizeof(char));
auto finalSize=replaceRemove(size,s4);
cout<<"Output array is "<<finalSize<<endl;
for(int i = 0;i<finalSize;++i){
    cout<<s4[i]<<endl;
    }

}
