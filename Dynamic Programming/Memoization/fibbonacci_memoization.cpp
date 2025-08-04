#include<iostream>
#include<unordered_map>
using namespace std;
long long fib(int n,unordered_map<int,long long>& memo){
    if(memo.find(n)!=memo.end()) return memo[n];
    if(n<=2) return 1;
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
}
int main(){
int n;
cout<<"Enter n : ";
cin>>n;

unordered_map<int,long long>memo;

cout<<"Corresponding Fibbonacci number : "<<fib(n,memo)<<endl;
}