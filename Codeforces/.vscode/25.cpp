#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    

     
    cin>>t;
    for(int i=0;i<t;i++){
    int n,k;
    cin>>n;
    int w[n];
    int h[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
        cin>>h[i];
    }
    sort(w,w+n);
    sort(h,h+n);
    int a=w[n-1];
    int b=h[n-1];
    int p=2*(a+b);
    cout<<p<<endl;
 }
}
