#include<iostream>
#include<unordered_map>
using namespace std;
long long GridTraveller(long long m,long long n, unordered_map<string,long long>& memo){
string temp=to_string(m)+","+to_string(n);
if(memo.find(temp)!=memo.end()) return memo[temp];
if(m==1 && n==1) return 1;
if(m==0 || n==0) return 0;
memo[temp]=GridTraveller(m-1,n,memo)+GridTraveller(m,n-1,memo);
return memo[temp];
}
int main(){
long long m,n;
cout<<"Enter the Dimension : ";
cin>>m>>n;
unordered_map<string,long long>memo;
cout<<"Number of Ways : "<<GridTraveller(m,n,memo)<<endl;
}