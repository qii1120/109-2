#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2==0){
        cout<<n;
    }
    else{
        cout<<n-1;
    }
    return 0;
}