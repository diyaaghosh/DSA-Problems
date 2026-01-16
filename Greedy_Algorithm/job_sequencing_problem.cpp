# include<iostream>
# include<vector>
# include<map>
# include<set>
# include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct job{
int id;
int deadline;
int profit;
job(int i,int d,int p){
    id=i;
    deadline=d;
    profit=p;}
};
int main(){
vector<job>jobs;
int n;
cout<<"Enter the dimension : ";
cin>>n;
cout<<"Enter job id, deadline and profit respectively : "<<endl;
 int max_deadline=0;
for(int i=0;i<n;i++){
    int id,d,p;
    cin>>id>>d>>p;
     max_deadline=max(max_deadline,d);
    jobs.push_back(job(id,d,p));
}
  sort(jobs.begin(), jobs.end(), [](job a, job b){
        return a.profit > b.profit;
    });

    vector<int> arr(max_deadline+1, -1);
    int ans=0;
    
    int x=0;
   
    for(auto it:jobs){
       
       for(int j = it.deadline ; j >= 0; j--){
            if(arr[j] == -1){
                arr[j] = it.id;
                ans += it.profit;
                break;}}
      x++;
    }
    cout<<"Maximum profit is : "<<ans<<endl;
}