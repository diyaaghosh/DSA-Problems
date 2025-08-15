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

int remove_fxn(int n){

    int c=n & (n-1);
    return c;
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;

int a=convert_to_binary(n);
cout<<"Binary Representation : "<<a<<endl;

cout<<"after removing the last set bit (right-most) : "<<convert_to_binary(remove_fxn(n));
}