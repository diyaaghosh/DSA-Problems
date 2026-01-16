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
    cout<<"Enter dimension : ";
    cin>>n;
    vector<int>arrival_time(n);
    vector<int>departure_time(n);
    cout<<"Enter arrival times : ";
    for(int i=0;i<n;i++){
        cin>>arrival_time[i];
    }
    cout<<"Enter departure times : ";
    for(int i=0;i<n;i++){
        cin>>departure_time[i];
    }
    sort(arrival_time.begin(),arrival_time.end());
    sort(departure_time.begin(),departure_time.end());
    int i=0;
    int j=0;
    int cnt=0;
    int maxi=INT_MIN;
    while(i<n && j<n){
        if(arrival_time[i]<=departure_time[j]){
            cnt++;
            i++;
        }
        else{
            j++;
            cnt--;
        }
        maxi=max(maxi,cnt);
    }
    while(i<n){
        cnt++;
        i++;
        maxi=max(maxi,cnt);
    }
    while(j<n){
        cnt--;
        j++;
        maxi=max(maxi,cnt);
    }
    cout<<"Minimum Platform req : "<<maxi;
}