#include<iostream>
using namespace std;
int main(){
    int t;
    int m,a,b,c;
    int r1,r2;
    
    cin>>t;
    for(int i=0;i<t;i++){
        int count=0;
        cin>>m;
        cin>>a;
        cin>>b;
        cin>>c;
        
        if(m>a && m>b){
            r1=m-a;
            r2=m-b;
            count+=(a+b);
            if((r1+r2)>c){
             count+=c;
            }
            else{
                count+=(r1+r2);
            }      
            
              }
              else if(m>a && m<=b){
                 r1=m-a;
                 count+=(a+m);
                 if((r1)>c){
             count+=c;
            }
            else{
                count+=r1;
            }   

    }
    else if(m<=a && m>b){
                 r2=m-b;
                 count+=(b+m);
                 if((r2)>c){
             count+=c;
            }
            else{
                count+=r2;
            }   

    }
    else if(m==a && m==b){
    count+=a+b;
}
else {
    count+=(2*m);
}
cout<<count<<endl;}

}