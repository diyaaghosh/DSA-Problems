# include<bits/stdc++.h>
using namespace std;
 
struct disjoint_set{
    vector<int> rank;
    vector<int> parent;
    disjoint_set(int n)
        : rank(n + 1, 0), parent(n + 1)
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
    void union_by_rank(int u,int v){
    int pu=find_parent(u); // ultimate parent of u
    int pv=find_parent(v); // ultimate parent of v
    if(pu==pv)return; // already in same component
    if(rank[pu]<rank[pv]){
        parent[pv]=pu;
    }
    else if(rank[pu]>rank[pv]){
        parent[pu]=pv;
    }
    else{
        parent[pu]=pv;
        rank[pv]++; 
    }
    }

};
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
int kruskal_algo(int n, int m, vector<vector<pair<int,int>>>& adj){
    vector<pair<int,pair<int,int>>>edges; // store all the edges
    for(int i=1;i<=n;i++){
        for(auto it :adj[i]){
            int adj_node=it.first;
            int weight=it.second;
            int node=i;
            edges.push_back({node,{adj_node,weight}});
        }
    }
    disjoint_set ds(n);
   sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
    return a.second.second < b.second.second;
});
    int sum=0;
    for(auto it:edges){
        int u=it.first;
        int v=it.second.first;
        int w=it.second.second;
        if(ds.find_parent(u)!=ds.find_parent(v)){
            sum+=w;
            ds.union_by_rank(u,v); // they are in different component so we can include this edge
        }
    }
    return sum;

}
int main(){
    int n;
     int m;// n= no of nodes , m= no of edges
    
    cout<<"Enter the number of nodes and edges : ";
   
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1); // initialize with n+1 for 1-based indexing
    cout << "For adjacency list by list method : " << endl;
    solve_by_list(n, m, adj);
  
    cout<<"The minimum sum by kruskal's algo is : "<<kruskal_algo(n,m,adj)<<endl;
   
    return 0;
}