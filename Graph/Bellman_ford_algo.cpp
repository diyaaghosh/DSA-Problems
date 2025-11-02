# include<bits/stdc++.h>
using namespace std;

void solve_by_list(int n, int m, vector<vector<pair<int,int>>>& adj) {
int maxi,mini;
cout<<"Enter the minimum range of the nodes in the graph : ";
    cin>>mini;
    cout<<"Enter the maximum range of the nodes in the graph : ";
    cin>>maxi;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout<<"edge : "<<i+1<<endl;
           u=mini+(rand()%(maxi-mini+1));
           cout<<"u = "<<u<<endl;
    v=mini+(rand()%(maxi-mini+1));
  
    if(u==v){
    while(u==v){
    v=mini+(rand()%(maxi-mini+1));
    }
    }
      cout<<"v = "<<v<<endl;
        int w=mini+(rand()%(maxi-mini+1));
        cout<<"w = "<<w<<endl;
        
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
vector<pair<int,pair<int,int>>>edges(int n, vector<vector<pair<int,int>>>& adj){

vector<pair<int,pair<int,int>>>edge; 
    for(int i=1;i<=n;i++){
    for(auto it: adj[i]){
        int v = it.first, w = it.second;
        edge.push_back({i, {v, w}});
        edge.push_back({v,{i,w}});
    
}
}

return edge;
}
vector<int> bellmanFord(int n,vector<pair<int,pair<int,int>>>&edges, int src) {

    vector<int> dist(n+1, INT_MAX);
	dist[src] = 0;

	for (int i = 0; i <= n-1; i++) {	    
		for (auto edge : edges) {
			int u = edge.first;
			int v = edge.second.first;
			int wt = edge.second.second;
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                if(i == n-1 )
                    return {-1};
                dist[v] = dist[u] + wt;
            }
		}
	}
    return dist;
}
int main(){
    int n,m;
    
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1); 
    cout << "For adjacency list by list method : " << endl;
    solve_by_list(n, m, adj);
    int src;
    printf("enter the source : ");
    scanf("%d",& src);
   vector<pair<int,pair<int,int>>>e=edges(n,adj);
    auto start = chrono::high_resolution_clock::now();
  
auto start1 = chrono::high_resolution_clock::now();
vector<int> result1 = bellmanFord(n, e, src);
   cout<<"Belman-Ford algorithm:"<<endl;
    for (int i=1;i<result1.size();i++)
        cout << result1[i] << " ";
        cout<<endl;
  auto end1 = chrono::high_resolution_clock::now();
chrono::duration<double, milli> elapsed1 = end1 - start1;
cout << "Time taken by Bellman-Ford algorithm: " << elapsed1.count() << " ms" << endl;
} 