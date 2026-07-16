# include<bits/stdc++.h>
using namespace std;

struct disjoint_set{
    vector<int> size;
    vector<int> parent;
    disjoint_set(int n)
        : size(n + 1, 1), parent(n + 1)
    {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    void union_by_size(int u,int v){
    int pu=find_parent(u); // ultimate parent of u
    int pv=find_parent(v); // ultimate parent of v
    if(pu==pv)return; // already in same component
    if(size[pu]<size[pv]){
        parent[pv]=pu;
        size[pu]+=size[pv];
    }
   
    else{
        parent[pu]=pv;
       size[pv]+=size[pu];
    }
    }

};
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x,y;
        map<long long,long long>mpp;
        cin>>n>>x>>y;
         disjoint_set ds(n);
        vector<long long>arr(n,0);
        for(long long i=0;i<n;i+=1){
            cin>>arr[i];
        }
        for(long long i=0;i<n;i++){
            mpp[arr[i]]=i;
            if((i+x)<n)ds.union_by_size(i,i+x);
            if((i+y)<n)ds.union_by_size(i,i+y);
        }
        vector<long long>original;
        for(long long i=1;i<=n;i+=1){
            original.push_back(i);
        }
        int flag=1;
        for(long long i=0;i<n;i++){
            if(ds.find_parent(i)!=ds.find_parent(mpp[i+1])){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}