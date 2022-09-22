#include<iostream>
using namespace std;
int main()
{
    int a[5];
    int b[5];
    int sum=0;
    for(int i=0;i<=4;i++)
    {
      cin>>a[i];
      cin>>b[i];
      sum=a[i]+b[i];
    cout<<sum<<"\n";
    }
    return 0;
}