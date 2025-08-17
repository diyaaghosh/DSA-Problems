#include<bits/stdc++.h>
using namespace std;
vector<int>divisor(int n){
    vector<int>list;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
       list.push_back(i);
       if(n/i !=i){
        list.push_back(n/i);
       }
        }
    }
    return list;
}
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
vector<int>list=divisor(n);
cout<<"divisor of "<<n<<" is : ";
sort(list.begin(),list.end());
for(int i=0;i<list.size();i++){
    cout<<list[i]<<" ";
}
}