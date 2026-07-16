#include<iostream>
using namespace std;
int main(){
    long long t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
      int b;
      b=a;
      int r=1;
      int y=0;
      //2013
      while(b>10){
        int re=b%10;
        
        y=y+re*r;
        r=r*10;
        b=b/10;
      }
      if(b==1 || b==10){
        int x=0;
        int p=1;
       while(a!=10){
        int rem=a%10;
  
        x=x+rem*p;
        p=p*10;
        a=a/10;
       }
       if(x>2 ) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
}