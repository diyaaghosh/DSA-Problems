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
   cin>>n;
   vector<int>start(n);
   vector<int>end(n);
   for(int i=0;i<n;i++){
    cin>>start[i];
   }
   for(int i=0;i<n;i++){
    cin>>end[i];
   }    
vector<pair<int,int>>meetings;
for(int i=0;i<n;i++){
    meetings.push_back({end[i],start[i]});
}
sort(meetings.begin(),meetings.end());

int cnt=0;
int freetime=0;
for(int i=0;i<meetings.size();i++){
if(freetime<meetings[i].second){
    cnt++;
    freetime=meetings[i].first;
}
}
cout<<"Maximum number of meetings that can be held in a room is : "<<cnt<<endl;
}