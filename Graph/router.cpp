# include<bits/stdc++.h>
using namespace std;
void implementation(int n,int m, vector<vector<pair<int,int>>>&adj_list,vector<vector<int>>&adj_mat, vector<pair<int,pair<int,int>>>&edges){
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
   int w= mini+rand()%(maxi-mini+1);
   cout<<"Edge : "<<i<<endl;
   cout<<"u = "<<u<<", v = "<<v<<", w : "<<w<<endl;
    adj_list[u].push_back({v,w});
    adj_list[v].push_back({u,w});
    adj_mat[u][v]=w;
    adj_mat[v][u]=w;
    edges.push_back({u,{v,w}});
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
vector<int>dijkstra(int n, vector<vector<pair<int,int>>>&adj_list,int source){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,source});
vector<int>dist(n+1,INT_MAX);
dist[source]=0;
while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int node=it.second;
    for(auto i:adj_list[node]){
int adj_node=i.first;
int adj_weight=i.second;
if(dist[adj_node]>dist[node]+adj_weight){
    dist[adj_node]=dist[node]+adj_weight;
    pq.push({dist[adj_node],adj_node});
}
    }
}


return dist;
}
vector<int>bellman_ford_algorithm(int n,vector<pair<int,pair<int,int>>>&edges,int source){
vector<int>dist(n+1,INT_MAX);
dist[source]=0;
for(int i=0;i<=n-1;i++){
    for(auto it:edges){
        int u=it.first;
        int v=it.second.first;
        int w=it.second.second;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            if(i==n-1){
                cout<<"Cycle detected";
                return {-1};
            }
             dist[v]=dist[u]+w;
        }
    }
}
return dist;
}
void floyd_warshall( vector<vector<int>>& mat){
    int n=mat.size();
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]==-1){
         mat[i][j]=1e9;
        }
        if(i==j)mat[i][j]=0;
    }
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]==1e9){
            mat[i][j]=-1;
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
    vector<vector<int>>adj_mat(n+1,vector<int>(n+1,-1));
    implementation(n,m,adj_list,adj_mat,edges);
    
    vector<vector<int>>ans;
    for(int i=0;i<=n;i++){
 vector<int>dist=dijkstra(n,adj_list,i);
 ans.push_back(dist);
    }
    cout<<"Router by Dijkstra Algo : \n";
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
     for(int i=0;i<=n;i++){
 vector<int>dist=bellman_ford_algorithm(n,edges,i);
 ans.push_back(dist);
    }
    cout<<"Router by Bellman Ford Algo : \n";
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
    vector<vector<int>>mat(n+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            mat[i][j]=adj_mat[i][j];
        }
    }
    cout<<"Router by Floyd Warshall Algorithm"<<endl;
     floyd_warshall(mat);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}