
#include<iostream>
using namespace std;

int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int i,j;
    
    cout<<"\nArray A"<<endl;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<a[i][j]<<" ";
        
        cout<<endl;
    }
    
    cout<<"\nRestore array A"<<endl;
    
    for(i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
       {
           a[i][j]=(10-a[i][j]);
           
           cout<<a[i][j]<<" ";
           
       }
       
       cout<<endl;
       
    }
    
    cout<<"\nElements a[2][0] after restore value: "<<a[2][0]<<endl;
    
    return 0;
    
}
