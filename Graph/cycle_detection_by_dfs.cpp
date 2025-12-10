# include<bits/stdc++.h>
using namespace std;
bool detect_cycle(int curr,int src,vector<vector<int>>&adj,vector<int>&vis){
    vis[curr]=1;
    for(auto it:adj[curr]){
        if(vis[it]==0){
        if(detect_cycle(it,curr,adj,vis)==true)return true;
        }
            else if(it!=src){
                cout<<"Cycle is detected"<<endl;
                return true;
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
  cout<<"DFS Traversal :\n";
  vector<int>vis(n+1,0);
  int flag=1;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
        if(detect_cycle(i,-1,adj,vis)==true){
           flag=0;
           break;

        }
    }
  }
  if(flag==1){
    cout<<"No cycle is detected"<<endl;
  }
   
    return 0;
}