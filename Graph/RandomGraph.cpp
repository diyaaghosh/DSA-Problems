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
void BFS_Traversal(vector<vector<int>>& adj,int n){
    vector<int>vis(n+1,0);
    queue<int>q;
    vector<int>bfs;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
       
        bfs.push_back(curr);
        for(auto it :adj[curr]){
       if(!vis[it]) {
    q.push(it);
    vis[it] = 1;
}
        }
    }
    cout<<"The BFS Traversal is : ";
    for(auto it : bfs){
        cout<<it<<" ";
    }
}
int main(){
    int n,m;// n= no of nodes , m= no of edges
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    cout<<"For adjacency matrix by matrix method : "<<endl;
    int maxi,mini;
    cout<<"Enter the minimum range of the nodes in the graph : ";
    cin>>mini;
    cout<<"Enter the maximum range of the nodes in the graph : ";
    cin>>maxi;
vector<vector<int>> adj(n+1);
for(int i=0;i<m;i++){
    int u,v;
    u=mini+(rand()%(maxi-mini+1));
    v=mini+(rand()%(maxi-mini+1));
    cout<<"The edge is : ("<<u<<","<<v<<")"<<endl;  
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
  for(int i=0;i<dfs.size();i++){
    cout<<dfs[i]<<" ";
  }
  cout<<endl;
  
    BFS_Traversal(adj,n);

   
    return 0;
}