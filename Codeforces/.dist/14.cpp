#include <iostream>
using namespace std;
int main() {
  long long t;
  cin>>t;
  for(long long i=0;i<t;i++){
   long long n;
   long long sum=0;
   cin>>n;

  long long arr[n];
  for(long long k=0;k<n;k++){
    cin>>arr[k];
  }
for(long long j=0;j<n;j++){
sum+=arr[j];
}
int ans=sum-(n-1);
cout<<ans<<endl;
  }


    return 0;
}