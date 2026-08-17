    #include<iostream>
    #include<vector>
    #include<unordered_map>
    #include<map>
    #include<set>
    #include<unordered_set>
    #include<algorithm>
    using namespace std;
int solve_by_recursion(int ind,int wt,vector<int>&W,vector<int>&val){
   
    if(ind==0){
        return (wt/W[0])*val[0];
    }
    
    int not_take=solve_by_recursion(ind-1,wt,W,val);
    int take=INT_MIN;
    if(wt>=W[ind]){
        take=val[ind]+solve_by_recursion(ind,wt-W[ind],W,val);
    }
    return max(take,not_take);
}
int solve_by_memoization(int ind,int wt,vector<int>&W,vector<int>&val,vector<vector<int>>&dp){
    
     if(ind==0){
        return (wt/W[0])*val[0];
    }
    if(dp[ind][wt]!=-1)return dp[ind][wt];
    int not_take=solve_by_memoization(ind-1,wt,W,val,dp);
    int take=INT_MIN;
    
    if(wt>=W[ind]){
        take=val[ind]+solve_by_memoization(ind,wt-W[ind],W,val,dp);
    }
    return dp[ind][wt]=max(take,not_take);
}
int solve_by_tabulation(int wt,vector<int>&W,vector<int>&val,vector<vector<int>>&dp){
    int n=W.size();
    for(int w=0;w<=wt;w++){
        dp[0][w]=(w/W[0])*val[0];
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=wt;w++){
            int not_take=dp[i-1][w];
            int take=INT_MIN;
    
            if(w>=W[i]){
            take=val[i]+dp[i][w-W[i]];
    }
    dp[i][w]=max(take,not_take);
        }
    }
    return dp[n-1][wt];
}
int solve_by_space_optimization(int wt,vector<int>&W,vector<int>&val){
    int n=W.size();
    vector<int>prev(wt+1,0);
    vector<int>curr(wt+1,0);
    for(int w=0;w<=wt;w++){
        prev[w]=(int)((w/W[0])*val[0]);
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=wt;w++){
            int not_take=prev[w];
    int take=INT_MIN;
    
    if(w>=W[i]){
        take=val[i]+curr[w-W[i]];
    }
    curr[w]=max(take,not_take);
        }
        prev=curr;
    }
    return prev[wt];
}
int solve_optimization_in_1d(int wt,vector<int>&W,vector<int>&val){
     int n=W.size();
    vector<int>prev(wt+1,0);
    
    for(int w=0;w<=wt;w++){
        prev[w]=(w/W[0])*val[0];
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=wt;w++){
            int not_take=prev[w];
    int take=INT_MIN;
    
    if(w>=W[i]){
        take=val[i]+prev[w-W[i]];
    }
    prev[w]=max(take,not_take);
        }
    }
    return prev[wt];
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int wt;
    cout<<"Enter the baggage weight : ";
    cin>>wt;
    cout<<"Enter the elements of wight array : ";
    vector<int>W(n,0);
    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    vector<int>val(n,0);
    cout<<"Enter the elements of value array : ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    vector<vector<int>>dp(n,vector<int>(wt+1,-1));
    vector<vector<int>>dp1(wt,vector<int>(wt+1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,wt,W,val)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n-1,wt,W,val,dp)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(wt,W,val,dp1)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(wt,W,val)<<endl;
    cout<<"Solving by 1D space optimization : "<<solve_optimization_in_1d(wt,W,val)<<endl;


}