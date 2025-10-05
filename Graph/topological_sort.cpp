# include<bits/stdc++.h>
using namespace std;
void dfs_traversal(int curr,vector<vector<int>>&adj,stack<int>&st,vector<int>& vis){
    vis[curr] = 1;
    for (auto it : adj[curr]) {
        if (!vis[it]) {
            dfs_traversal(it, adj, st, vis);
        }
    }
    st.push(curr);
}

void topological_sort(int n,vector<vector<int>> & adj){
    vector<int>toposort_array;
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs_traversal(i,adj,st,vis);
        }
    }
     cout<<"Topological Sort Order : \n";
    while(!st.empty()){
          cout<<st.top()<<" ";
toposort_array.push_back(st.top());
        st.pop();
    }
}
void solve_by_list(int n,int m, vector<vector<int>>& adj){
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter the edge (u,v) : ";
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    cout<<"The adjacency list is : "<<endl;
     for (int i = 0; i <n; i++) {
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
    vector<vector<int>> adj(n);
    cout<<"For adjacency list by list method : "<<endl;
    solve_by_list(n,m,adj);
    topological_sort(n,adj);
    return 0;
}