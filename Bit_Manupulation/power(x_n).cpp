#include<bits/stdc++.h>
using namespace std;
double power(int n,double x){
    bool sign=true;// positive power
    if(n<0){
         n = -n;
    sign=false;
    }
    double ans=1;
    while(n>0){
        if(n%2==1){
            ans*=x;
            n=n-1;
        
        }
        else{
            n=n/2;
            x=x*x;
        }
    }
    return (sign==true)?ans:(double)(1.0/(ans));
}
int main(){
    double n,x;
    cout<<"enter number : ";
    cin>>x;
    cout<<"enter the power : ";
    cin>>n;
    double ans=power(n,x);
    cout<<x<<"^"<<n<<" = "<<ans;
}