# include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               mpp[arr[i][j]]++;
            }
        }
        int flag=1;
        int max_ele_in_row=n-1;
        int total_ele=n*max_ele_in_row;
        for(auto[a,b]:mpp){
            if(b>total_ele){
                cout<<"No"<<endl;
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<"Yes"<<endl;
        }
    }
}