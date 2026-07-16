# include<bits/stdc++.h>
using namespace std;
int main(){
string str;
cin>>str;
map<char,int>mpp;
for(int i=0;i<str.size();i+=1){
    mpp[str[i]]++;
}
if(mpp.size()%2==0){
    cout<<"CHAT WITH HER!"<<endl;
}
else{
    cout<<"IGNORE HIM!"<<endl;
}

}