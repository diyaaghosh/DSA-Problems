#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,int>cost,cnt;
         int curr=arr[0];
         int step=0;
        while(true){
            cost[curr]=step;
            cnt[curr]=1;
            if(curr==1)break;
            step++;
            if(curr%2==0){
                curr=curr/2;
            }
            else curr+=1;
        }
        if(arr[0]==1){
            cost[2]=1;
            cnt[2]=1;
        }
         for(int i=1;i<n;i++){
        int curr=arr[i];
        int flag=0;
        int steps=0;
        while(true){
            if(cost.find(curr)!=cost.end()){
                cost[curr]+=steps;
                cnt[curr]++;
            }
            if(curr==1)break;
             if(curr%2==0){
                curr=curr/2;
            }
            else curr+=1;
            steps++;
        }
        if(arr[i]==1 && cost.find(2)!=cost.end() && flag==0){
    cost[2] += 1;
    cnt[2]++;
    flag=1;
}
    }
    int ans=INT_MAX;
    for(auto [a,b]:cnt){
        if(b==n){
            ans=min(ans,cost[a]);
        }
    }
    cout<<ans<<endl;
    }
   
}