# include<bits/stdc++.h>
using namespace std;
// memoization
int ninja_training(vector<vector<int>> & points, int day, int last, vector<vector<int>> & dp){
 
    int m=points[0].size();
  if(day==0){
    int maxi=0;
    for(int task=0;task<m;task++){
        if(task!=last){
            maxi=max(maxi,points[0][task]);
        }
    }
    return maxi;
  }
  
  if(dp[day][last]!=-1)return dp[day][last];
  int maxi=0;
  for(int task=0;task<m;task++){
    if(task!=last){
        int point=points[day][task]+ninja_training(points,day-1,task,dp);
        maxi=max(maxi,point);
    }
  }
  dp[day][last]=maxi;
  return dp[day][last];
}
// tabulation
int ninja_training_tabulation(vector<vector<int>> & points, int day, int last, vector<vector<int>> & dp){
 
    int m=points[0].size();
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<points.size();day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<m;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[day-1][3];
}
int main(){
    int n;
    cout<<"enter day : ";
    cin>>n; 
    int m;
    cout<<"enter task no : ";
    cin>>m;
    vector<vector<int>> points(n,vector<int>(m,0));
    cout<<"enter the points : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>points[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(m+1,-1));
    int a=ninja_training(points,n-1,m,dp);
    cout<<a;
    vector<vector<int>> dp2(n,vector<int>(m+1,0));
    int b=ninja_training_tabulation(points,n,m,dp2);
    cout<<endl;
    cout<<b;
}