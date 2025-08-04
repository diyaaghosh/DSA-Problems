#include<iostream>
#include<vector>
using namespace std;
long long fib(long long n){
    vector<long long>table(n+1,0);
    table[1]=1;
    for(int i=0;i<=n;i++){
        if(i+1<=n){
            table[i+1]+=table[i];
        }
        if(i+2<=n){
              table[i+2]+=table[i];
        }
    }
    return table[n];
}
int main(){
cout<<fib(6)<<endl;
cout<<fib(7)<<endl;
cout<<fib(8)<<endl;
cout<<fib(50)<<endl;
}