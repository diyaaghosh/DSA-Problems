# include<bits/stdc++.h>
using namespace std;
int min_sum(int n, vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>vis(n,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int weight=it.first;
        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=weight;
        for(auto i:adj[node]){
            int adj_node = i.first;
            int adj_weight = i.second;
            if(!vis[adj_node]){
                pq.push({adj_weight,adj_node});
            }
        }
    }
    return sum;
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
    // Example usage of min_sum (optional, remove if not needed)
    cout << "Minimum sum (MST weight): " << min_sum(n+1, adj) << endl;
   
} 
