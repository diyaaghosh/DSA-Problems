#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    if((n&1)==1){
        cout<<n<<" is odd"<<endl;
    }
    else{
         cout<<n<<" is even"<<endl;
    }
}