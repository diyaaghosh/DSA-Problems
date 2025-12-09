# include<bits/stdc++.h>
using namespace std;

bool detect_cycle(vector<vector<int>>& adj,int n,int src,vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adj_node:adj[node]){
            if(!vis[adj_node]){
                vis[adj_node]=1;
                q.push({adj_node,node});
            }
            else{
                if(parent!=adj_node){
                    cout<<"Cycle is detected"<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int n,m;// n= no of nodes , m= no of edges
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    cout<<"For adjacency matrix by matrix method : "<<endl;
vector<vector<int>> adj(n+1);
for(int i=0;i<m;i++){
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
int flag=1;
   vector<int>vis(n+1,0);
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        vis[i]=1;
        if(detect_cycle(adj,n,i,vis)){
            flag=0;
            break;
        }
    }
   }
   if(flag==1)cout<<"No cycle is detected"<<endl;
    return 0;
}