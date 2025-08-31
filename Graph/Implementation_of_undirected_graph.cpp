# include<bits/stdc++.h>
using namespace std;
void solve_by_matrix(int n,int m){
     vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for(int i=0;i<=m;i++){
        int u,v;
        cout<<"Enter the edge (u,v) : ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<"The adjacency matrix is : "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
}
void solve_by_list(int n,int m){
    vector<int>adj[n+1];
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
}
int main(){
    int n,m;// n= no of nodes , m= no of edges
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    cout<<"For adjacency matrix by matrix method : "<<endl;
    solve_by_matrix(n,m);
    cout<<"For adjacency list by list method : "<<endl;
    solve_by_list(n,m);
    return 0;
}
