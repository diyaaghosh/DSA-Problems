# include<bits/stdc++.h>
using namespace std;
struct disjoint_set{
    vector<int>rank;
    vector<int>parent;
disjoint_set(int n):
rank(n+1,0),parent(n+1){
for(int i=0;i<=n;i++){
    parent[i]=i;
}
}
int find_parent(int u){
    if(u==parent[u])return u;
    return parent[u]=find_parent(parent[u]);
}
void union_by_rank(int u,int v){
    int pu=find_parent(u);
    int pv=find_parent(v);
    int r1=rank[pu];
    int r2=rank[pv];
    if(r1<r2){
        parent[pu]=pv;
    }
    else if(r2<r1){
        parent[pv]=pu;
    }
    else{
           parent[pu]=pv;
          rank[pv]++;
    }
}
};
void implementation(int n,int m, vector<vector<pair<int,int>>>&adj_list,vector<vector<int>>&adj_mat, vector<pair<int,pair<int,int>>>&edges){
    set<pair<int,int>>used_track;
    int mini;
    cout<<"Enter the mininum range : ";
    cin>>mini;
    int maxi;
    cout<<"Enter the maximum range : ";
    cin>>maxi;
for(int i=1;i<=m;i++){
    int u,v;

   u=mini+rand()%(maxi-mini+1);
   v=mini+rand()%(maxi-mini+1);
   if(u==v){
    while(u==v){
           v=mini+rand()%(maxi-mini+1);
    }
   }
   if(used_track.count({min(u,v),max(u,v)})){
    while(used_track.count({min(u,v),max(u,v)})){
          u=mini+rand()%(maxi-mini+1);
   v=mini+rand()%(maxi-mini+1);
   if(u==v){
    while(u==v){
           v=mini+rand()%(maxi-mini+1);
    }
   }
    }
   }
used_track.insert({min(u,v),max(u,v)});
   int w= mini+rand()%(maxi-mini+1);
   cout<<"Edge : "<<i<<endl;
   cout<<"u = "<<u<<", v = "<<v<<", w : "<<w<<endl;
    adj_list[u].push_back({v,w});
    adj_list[v].push_back({u,w});
    adj_mat[u][v]=w;
    adj_mat[v][u]=w;
    if(u<v)
    edges.push_back({u,{v,w}});
    else if(v<u)
    edges.push_back({v,{u,w}});
}
cout<<"Adjacency List : \n";
for(int i=1;i<=n;i++){
    cout<<i<<"->";
    for(auto it:adj_list[i]){
        cout<<" { "<<it.first<<" , "<<it.second<<" } ";
    }
    cout<<endl;
}
cout<<"Adjacency Matrix : \n";
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<adj_mat[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"Edge List : \n";
for(auto i:edges){
cout<<i.first<<" , "<<i.second.first<<", "<<i.second.second<<endl;
}
}
void kruskal_algorithm(int n, vector<pair<int,pair<int,int>>>&edges){
    disjoint_set ds(n);
sort(edges.begin(),edges.end(),[](auto &a,auto &b){
    return a.second.second<b.second.second;
});
int path_sum=0;
for(auto it:edges){
    int u=it.first;
    int v=it.second.first;
    int w=it.second.second;
if(ds.find_parent(u)!=ds.find_parent(v)){
    path_sum+=w;
ds.union_by_rank(u,v);
}
else{
    cout<<"Cycle Detects"<<endl;
   
}
}
cout<<"Path sum by Kruskal Algorithm : "<<path_sum<<endl;
}
int main(){
    int n,m;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<"Enter the number of Edges : ";
    cin>>m;
    vector<pair<int,pair<int,int>>>edges;
    vector<vector<pair<int,int>>>adj_list(n+1);
    vector<vector<int>>adj_mat(n+1,vector<int>(n+1,0));
    implementation(n,m,adj_list,adj_mat,edges);
    kruskal_algorithm(n,edges);
}