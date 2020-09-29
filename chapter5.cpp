// Example program
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
void evenOdd(vector<int> *A_ptr){
    vector<int> &A = *A_ptr;
   int  ieven=0; 
   int iOdd= A.size()-1;
    while(ieven<iOdd){
        if(A[ieven]%2==0){
            ieven++;
            }
            else{
                swap(A[ieven],A[iOdd--]);
                }
        }
    }
    
    void randomGen(vector<int> *A_ptr, int k){
    vector<int> &A = *A_ptr;
        default_random_engine seed;

            for(int i=0;i<k;i++){
            //uniform_int_distribution<int> distribution(i,static_cast<int>( A.size())-1);
            swap(A[i],A[uniform_int_distribution<int>{i,static_cast<int>( A.size())-1}(seed)]);
            
           

    
                }
    }
    
    double Power(double x,int y){
        
        float res=1.0;
        while(y)
        {
            if(x && 1){
                res*=x;
                }
                y>>=1;
                res=res*Power(Power(x,y),2);
            }
            return res;
        }
    
    typedef enum{red,white,blue} Color;
    
void dutchFlag(vector<Color> *A_ptr, int iP){
    vector<Color> &A = *A_ptr;
    
   
   int  iS=0; 
   int iL= A.size()-1;
   Color pivot = A[iP];
    for(int i=0;i<A.size();i++){
        if(A[i]<pivot){
                swap(A[i],A[iS++]);
                
                }
        }
        
            for(int i=A.size();i>=0;i--){
        if(A[i]>pivot){
                swap(A[i],A[iL--]);
                
                }
        }
    }
    
    double parity(unsigned long long x){
        int num=0;
        while(x){
            num^=(x&1);
            x>>=1;
            
            }
        return num;
        }
int main()
{

cout<<Power(2.0,5)<<endl;
cout<<parity(11)<<endl;

vector<int> A1={3,7,5,11};
vector<int> *A1_ptr=&A1;
randomGen(A1_ptr,3);

for(int i =0; i<A1.size();i++){
    cout<<(A1[i]);
}
}

