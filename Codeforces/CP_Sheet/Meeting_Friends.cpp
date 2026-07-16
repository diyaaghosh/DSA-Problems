#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>temp={a,b,c};
    sort(temp.begin(),temp.end());
    cout<<-temp[0]+temp[2]<<endl;
}