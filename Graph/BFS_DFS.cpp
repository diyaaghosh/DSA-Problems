# include<bits/stdc++.h>
using namespace std;
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
void dfs_traversal(int n,vector<int>&vis,vector<vector<pair<int,int>>>&adj_list,int curr,vector<int>&dfs){
vis[curr]=1;
dfs.push_back(curr);
for(auto it:adj_list[curr]){
    int node=it.first;
    if(!vis[node]){
        dfs_traversal(n,vis,adj_list,node,dfs);
    }
}
}
void bfs_traversal(int n,vector<vector<pair<int,int>>>&adj_list,vector<int>&bfs){
    queue<int>q;
    vector<int>vis(n+1,0);
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        bfs.push_back(curr);
        for(auto it:adj_list[curr]){
            if(!vis[it.first]){
                q.push(it.first);
                vis[it.first]=1;
            }
        }
    }

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
    vector<int>vis(n+1,0);
    vector<int>dfs;
    dfs_traversal(n,vis,adj_list,1,dfs);
    cout<<"The DFS Traversal is : \n";
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    vector<int>bfs;
    bfs_traversal(n,adj_list,bfs);
     cout<<"The BFS Traversal is : \n";
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }
}
