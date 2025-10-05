# include<bits/stdc++.h>
using namespace std;
void dfs_traversal(int curr, vector<vector<pair<int, int>>>& adj, stack<int>& st, vector<int>& vis) {
    vis[curr] = 1;
    for (auto it : adj[curr]) {
        int neighbor = it.first;
        if (!vis[neighbor]) {
            dfs_traversal(neighbor, adj, st, vis);
        }
    }
    st.push(curr);
}

void topological_sort(int n, vector<vector<pair<int, int>>>& adj, stack<int>& st) {
    vector<int> vis(n , 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_traversal(i, adj, st, vis);
        }
    }
}
void shortest_distance(int n,int source_node,vector<int>& dist,vector<vector<pair<int,int>>>& adj, stack<int>& st){
  while(!st.empty()){
    int node=st.top();
    st.pop();
    for(auto it : adj[node]){
        int adj_node=it.first;
        int wt=it.second;
        if(dist[node]+wt<dist[adj_node]){
            dist[adj_node]=dist[node]+wt;

        }
    }
  }
}
void solve_by_list(int n, int m, vector<vector<pair<int,int>>>& adj) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter the edge (u,v) : ";
        cin >> u >> v;
        int w;
        cout<<"Enter edge weight : ";
        cin >> w;
        adj[u].push_back({v,w});
      
    }
    cout << "The adjacency list is : " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (size_t j = 0; j < adj[i].size(); j++) {
            cout <<" { "<< adj[i][j].first << "," << adj[i][j].second<<" } " << " ";
        }
        cout << endl;
    }
}


int main(){
    int n,m;// n= no of nodes , m= no of edges
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
vector<vector<pair<int,int>>> adj(n ); 
    cout<<"For adjacency list by list method : "<<endl;
    solve_by_list(n,m,adj);
     stack<int>st;
    topological_sort(n,adj,st);
     vector<int>dist(n ,INT_MAX);
     int source_node;
     cout<<"Enter the source node : ";
     cin>>source_node;
     dist[source_node]=0;
    shortest_distance(n,source_node,dist,adj,st);
    cout<<"The shortest distance from source node "<<source_node<<" to all other nodes is : "<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"Distance to node "<<i<<" is : "<<"INF"<<endl;
        }
        else{
            cout<<"Distance to node "<<i<<" is : "<<dist[i]<<endl;
        }
    }
    return 0;
}