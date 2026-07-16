#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>w(n,0);
        for(int i=0;i<n;i++){
            cin>>w[i];
        }
        int count_zero=0;
        int count_one=0;
        int count_two=0;
        for(int i=0;i<n;i++){
            if(w[i]==0)count_zero+=1;
            else if(w[i]==1)count_one+=1;
            else count_two+=1;
        }
        int ans=0;
        ans+=count_zero;
        int pair_of_one_two=min(count_two,count_one);
        ans+=pair_of_one_two; // (2+1=3 divisible by 3)
        int left_one=count_one-pair_of_one_two;
        int left_two=count_two-pair_of_one_two;
        if(left_one>=3)ans+=(left_one/3); //(1+1+1=3 divisible by 3)
        if(left_two>=3)ans+=(left_two/3); // (2+2+2=6 divisible by 3)
        cout<<ans<<endl;
    }
}