#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int n,k,p;
    cin>>n;
    cin>>k;
    cin>>p;
    if(n*p<abs(k)){
        cout<<-1<<endl;
       
    }
    else{
        int rem=abs(k)%p;
        int div=abs(k)/p;
        if(rem>=1){
            rem=1;
        }
        else{
            rem=0;
        }
        cout<<rem+div<<endl;
    }
    }
}