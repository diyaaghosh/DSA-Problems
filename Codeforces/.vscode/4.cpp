#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i+=1){
        int sum=0;
        int n;
        cin>>n;
        int a=n%10;
        n=n/10;
        int b=n%10;
        sum+=a+b;
        cout<<sum<<endl;
    }
}