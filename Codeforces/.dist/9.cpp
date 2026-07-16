#include<iostream>
#include <string>
using namespace std;
int main(){
  long long t;
    cin>>t;
    for(int i=0;i<t;i++){
        int num;
        cin>>num;
        string input=to_string(num);
        if(input.length()<3){ cout<<"NO"<<endl;
        continue;}
        else{
               int firstpart=stoll(input.substr(0,2));
               string t=input.substr(2);
       int lastpart=stoll(t);
       if(firstpart!=10 || lastpart<2 || t!=to_string(lastpart)){
        cout<<"NO"<<endl;
       }
       else{
        cout<<"YES"<<endl;
       }
    }
}
}