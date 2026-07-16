#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
     vector<long long>points;

     
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n;
        cin>>x;
        vector<long long>points;
       points.push_back(0);
       for(int j=0;j<n;j++){
        int point;
        cin>>point;
        points.push_back(point);
       }
       points.push_back(x);
       int maxi=INT_MIN;
       int m=points.size();
       for(int j=1;j<m;j++){
        if(j==m-1){
            int r=2*(points[j]-points[j-1]);
            maxi=max(maxi,r);
        
        
        
        }
        else{
            int r=(points[j]-points[j-1]);
             maxi=max(maxi,r);
        }
       }
    cout<<maxi<<endl;

    }
}