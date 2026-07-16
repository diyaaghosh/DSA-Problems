# include<bits/stdc++.h>
using namespace std;
long long minimum(long long a,long long b){
    if(a<b)return a;
    else return b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,x;
        cin>>a>>b>>x;
        unordered_map<long long,long long>mpp1;
        unordered_map<long long ,long long>mpp2;
        int steps=0;
        mpp1[a]=0;
        while(a){
            long long rem=(long long)(a/x);
            steps++;
            if(mpp1.find(rem)==mpp1.end()){
                mpp1[rem]=steps;
            }
            a=rem;
        }
        steps=0;
        mpp2[b]=0;
        while(b){
            long long rem=(long long)(b/x);
            steps++;
            if(mpp2.find(rem)==mpp2.end()){
            mpp2[rem]=steps;}
            b=rem;
        }
        long long mini=INT_MAX;
        for(auto [x,y]:mpp1){
            for(auto [c,d]:mpp2){
                long long curr=y+d+abs(x-c);
                mini=minimum(mini,curr);
            }
        }
        cout<<mini<<endl;
    }

}