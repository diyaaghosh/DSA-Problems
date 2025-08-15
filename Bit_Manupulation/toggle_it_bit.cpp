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
bool check_ith_bit_set(int n,int x){
if(((1<<x)&n)!=0){
    return true;
}
else{  
return false;
}
}
int change_ith_bit(int n,int x){
    if(check_ith_bit_set(n,x)==false){
        int b=(n | (1<<x));
        return b;
    }
    else{
        int b=(n & (~(1<<x)));
        return b;
    }
}
int toggle_ith_bit(int n,int x){
    int b=(n ^ (1<<x));
    return b;
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
int ans=change_ith_bit(n,x);
cout<<"toggling ith bit by checking set or unset: "<<ans<<endl;
ans=toggle_ith_bit(n,x);
cout<<"toggling ith bit by XOR operation: "<<ans<<endl;
}