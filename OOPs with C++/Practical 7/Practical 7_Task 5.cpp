
#include<iostream>
using namespace std;

int main()
{
    char A[4][4];
    int i,j;
    
   
    for(i=0;i<4;i++)
    {
         for(j=0;j<4;j++)
         {
            A[i][j]='*';
         }
    }
    
    cout<<endl; 
    
    for(i=0;i<4;i++)
    {
         for(j=0;j<=i;j++)
         {
             cout<<A[i][j]<<" ";
         }
         cout<<endl;
    }
    
    return 0;
    
}
    
