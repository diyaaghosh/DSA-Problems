# include<bits/stdc++.h>
using namespace std;

void shortest_distance(int n, int m, vector<vector<pair<int,int>>>& adj,vector<int>& dist){
queue<pair<int,int>>q;
q.push({1,0}); //{node,distance}
dist[1]=0;
while(!q.empty()){
    auto it =q.front();
    q.pop();
    int node=it.first;
    int dis=it.second;
    for(auto i:adj[node]){
int adj_node=i.first;
int edge_weight=i.second;
if(dis+edge_weight<dist[adj_node]){
    dist[adj_node]=dis+edge_weight;
    q.push({adj_node,dist[adj_node]});
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
        adj[v].push_back({u,w});
    }
    cout << "The adjacency list is : " << endl;
    for (int i = 1; i <= n; i++) {
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
    vector<vector<pair<int,int>>> adj(n+1); // initialize with n+1 for 1-based indexing
    cout << "For adjacency list by list method : " << endl;
    solve_by_list(n, m, adj);
    vector<int>dist(n+1,INT_MAX);
    shortest_distance(n,m,adj,dist);
    cout<<"The shortest distance from source node 1 to all other nodes is : "<<endl;
    
   
} 
