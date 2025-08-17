#include<bits/stdc++.h>
using namespace std;
int func(int n){
    if(n%4==1)return 1;
   else if(n%4==2)return n+1;
   else if(n%4==3)return 0;
   else return n;
}
int gen_func(int l,int r){
    int a=func(l-1);
    int b=func(r);
    int c=a^b;
    return c;
}
int main(){
    cout<<"Press 1 : For finding XOR in range of 1 and n \nPress 2: For finding XOR b/w left and right range \n";
    int press;
    cout<<"Press : ";
    cin>>press;
    if(press==1){
    int n;
    cout<<"Enter the range : ";
    cin>>n;
    int ans=func(n);
    cout<<"xor of numbers b/w 1 and "<<n<<" is "<<ans;
    }
    else if(press==2){
  int l,r;
    cout<<"Enter left range : ";
    cin>>l;
    cout<<"Enter Right range : ";
    cin>>r;
    int ans=gen_func(l,r);
    cout<<"xor of numbers b/w "<<l<<" and "<<r<<" is "<<ans;
    }
    else{
        cout<<"Invalid Press\n";
    }
  
}