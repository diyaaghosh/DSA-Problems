# include<bits/stdc++.h>
using namespace std;

void solve_by_list(int n, int m, vector<vector<pair<int,int>>>& adj) {
int maxi,mini;
cout<<"Enter the minimum range of the nodes in the graph : ";
    cin>>mini;
    cout<<"Enter the maximum range of the nodes in the graph : ";
    cin>>maxi;
    set<pair<int,int>> existing_edges;

    if (maxi > n) maxi = n;
    if (mini < 1) mini = 1;
  
    for (int i = 0; i < m; i++) {
    int u = mini + (rand() % (maxi - mini + 1));
    int v = mini + (rand() % (maxi - mini + 1));

    while (u == v) {
        v = mini + (rand() % (maxi - mini + 1));
    }

    // ensure unique edges
    while (existing_edges.count({u, v}) || existing_edges.count({v, u})) {
        u = mini + (rand() % (maxi - mini + 1));
        v = mini + (rand() % (maxi - mini + 1));
        while (u == v)
            v = mini + (rand() % (maxi - mini + 1));
    }

    existing_edges.insert({u, v});
    existing_edges.insert({v, u});

    int w = mini + (rand() % (maxi - mini + 1));
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});

    cout << "Edge " << i+1 << ": " << u << " --(" << w << ")--> " << v << endl;
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

void dijkstra_util(int n,vector<vector<pair<int,int>>>& adj,vector<int>& dist,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& pq,vector<int>&parent,int dest,int src){
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adj_node=it.first;
            int wt=it.second;
            if(dis+wt<dist[adj_node]){
                dist[adj_node]=dis+wt;
                parent[adj_node]=node;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    if (dist[dest] == INT_MAX) {
    cout << "No path exists\n";
    return;
}
    cout<<"The shortest distance from source to destination is : "<<dist[dest]<<endl;
    int node=dest;
    vector<int>arr;
    while(node!=src){
        arr.push_back(node);
        node=parent[node];
    }
      arr.push_back(src);
    reverse(arr.begin(),arr.end());
    cout<<"The shortest path from source to destination is : ";
    for(auto it: arr){
        cout<<it<<" ";
    }
}

int main(){
    srand(time(0));

    int n,m;
    
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1); 
    cout << "For adjacency list by list method : " << endl;
    solve_by_list(n, m, adj);
    int src;
    printf("enter the source : ");
    scanf("%d",& src);

int dest;
    printf("enter the destination : ");
    scanf("%d",& dest);
      vector<int> dist(n+1,INT_MAX);
      vector<int>parent(n+1);
      for(int i=1;i<=n;i++){
        parent[i]=i;
      }
      dist[src]=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,src});
     
      dijkstra_util(n, adj, dist, pq,parent,dest,src);
   

} 