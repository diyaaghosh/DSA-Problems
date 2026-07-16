#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
    
        long long n;
        cin>>n;
       long long rem=n%12;
       if(n==10)cout<<-1<<endl;
      else if(rem==10){
       
        cout<<22<<" "<<n-22<<endl;
       }
       else{
        cout<<rem<<" "<<n-rem<<endl;
       }
        
        
        }
    
}