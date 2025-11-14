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
bool dfs(int n,int curr,int current_color,vector<int>&color,vector<vector<pair<int,int>>>&adj_list){
color[curr]=current_color;
for(auto it:adj_list[curr]){
    int node=it.first;
    if(color[node]==-1){
        if(dfs(n,node,!current_color,color,adj_list)==false)return false;
    }
    if(color[node]==current_color)return false;
}
return true;
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
    vector<int>color(n+1,-1);
   for(int i=1;i<=n;i++){
    if(color[i]==-1){
       bool ans= dfs(n,i,0,color,adj_list);
       if(ans==false){
        cout<<"The Graph is not Bipartite"<<endl;
        return 0;
    }
   }
    
   
   }
   cout<<"The Graph is Bipartite"<<endl;
    
}