# include<iostream>
# include<vector>
# include<map>
# include<set>
# include<algorithm>
#include<stack>
#include<queue>
using namespace std;
 
int main(){
    int n;
    cout<<"Enter the Dimension :  ";
    cin>>n;
    vector<int>burst_time(n);
    cout<<"Enter the burst times of the processes : ";
    for(int i=0;i<n;i++){
        cin>>burst_time[i];
    }
    sort(burst_time.begin(),burst_time.end());
    vector<int>s;
    int total_timing=0;
    for(int i=0;i<n;i++){
        total_timing+=burst_time[i];
        s.push_back(total_timing);
    }
    int ans=0;
    for(int i=0;i<s.size()-1;i++){
        ans+=s[i];
    }
   
    int avg=ans/n;
    cout<<"Average waiting time is : "<<avg<<endl;

}