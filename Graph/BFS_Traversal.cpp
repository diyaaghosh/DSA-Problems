# include<bits/stdc++.h>
using namespace std;
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
vector<vector<int>> adj(n+1);
for(int i=0;i<=m;i++){
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

    BFS_Traversal(adj,n);
    return 0;
}