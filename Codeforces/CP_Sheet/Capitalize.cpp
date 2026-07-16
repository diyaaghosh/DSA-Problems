#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    if(str[0]>=97 && str[1]<=122){
        str[0]-=32;
    }
    cout<<str<<endl;
}