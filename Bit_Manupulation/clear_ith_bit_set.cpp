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
int convert_to_decimal(int n){
    int p=1;
    int sum=0;
    while(n){
        int rem=n%10;
        n=n/10;
        sum+=(rem*p);
        p*=2;
    }
    return sum;
}

int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;

int a=convert_to_binary(n);
cout<<"Binary Representation : "<<a<<endl;
int x;
cout<<"enter bit : ";
cin>>x;

int b=n&(~(1<<x));

cout<<"decimal representation after setting the i-th bit :"<<b;
}