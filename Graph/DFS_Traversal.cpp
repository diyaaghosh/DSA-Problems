# include<bits/stdc++.h>
using namespace std;
void dfs_traversal(int curr,vector<vector<int>>&adj,vector<int>& dfs,vector<int>& vis){
    vis[curr]=1;
    dfs.push_back(curr);
    for(auto it : adj[curr]){
        if(! vis[it]){
            vis[it]=1;
            dfs_traversal(it,adj,dfs,vis);
        }
    }
}
int main(){
    int n,m;// n= no of nodes , m= no of edges
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    cout<<"For adjacency matrix by matrix method : "<<endl;
vector<vector<int>> adj(n+1);
for(int i=0;i<m;i++){
    int u,v;
    cout<<"Enter the edge (u,v) : ";
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
    cout<<"The adjacency list is : "<<endl;
     for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
         for (size_t j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout<<endl;
    }
  cout<<"DFS Traversal :\n";
  vector<int>vis(n+1,0);
  vector<int>dfs;
  dfs_traversal(1,adj,dfs,vis);
  for(int i=0;i<n;i++){
    cout<<dfs[i]<<" ";
  }
  cout<<endl;
   
    return 0;
}