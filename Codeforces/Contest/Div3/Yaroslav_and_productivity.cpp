# include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long>arr(n,0);
        for(long long i=0;i<n;i+=1){
            cin>>arr[i];
        }
        vector<long long>post(m,0);
        for(long long i=0;i<m;i++){
            cin>>post[i];
        }
        vector<long long>prefix_sum(n,0);
        vector<long long>prefix_sum_neg(n,0);
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=arr[i];
            prefix_sum[i]=sum;
            prefix_sum_neg[i]=(-sum);
        }
        long long motivation=prefix_sum[n-1];
        for(long long i=0;i<m;i++){
            long long pos=post[i]-1;
            if(prefix_sum_neg[pos]>prefix_sum[pos]){
                long long score=prefix_sum_neg[pos]+(prefix_sum[n-1]-prefix_sum[pos]);
                motivation=max(motivation,score);
            }
        }
        cout<<motivation<<endl;
    }
}