#include<bits/stdc++.h>
using namespace std;
int convert_to_binary(int n){
    vector<int>ans;
    while(n){
        int rem=n%2;
        ans.push_back(rem);
        n=n/2;
    }
    int p=1;
    int sum=0;
  for(int i=0;i<ans.size();i++){
sum=sum+ans[i]*p;
p=p*10;
  }
  return sum;
}

int count(int n){

   int cnt=0;
   while(n){
    n=n&(n-1);
    cnt++;
   }
   return cnt;
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
cout<<"no of set bits : "<<count(n)<<endl;

}