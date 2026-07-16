#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
      long long n;
        cin>>n;
        long long a[n];
        for(long long k=0;k<n;k++){
            cin>>a[k];
        }
        sort(a,a+n);
        int sum=0;
        for(long long j=1;j<n;j++){
        sum+=(a[j]-a[j-1]);
        }
        cout<<sum<<endl;
    }
}