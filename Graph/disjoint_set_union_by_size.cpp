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
    int n;
    cout<<"Enter n : ";
    cin>>n;
    disjoint_set ds(n);
    ds.union_by_size(1,2);
    ds.union_by_size(2,3);
    ds.union_by_size(4,5);
    ds.union_by_size(6,7);
    ds.union_by_size(5,6);
      if(ds.find_parent(3)==ds.find_parent(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Not in same component"<<endl;
    }
   ds.union_by_size(3,7);
    if(ds.find_parent(3)==ds.find_parent(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Not in same component"<<endl;
    }
    
    return 0;
}