#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
bool canSum(long long targetsum,vector<long long>nums){
vector<bool>temp(targetsum+1,false);
temp[0]=true;
for(int i=0;i<temp.size();i++){
    if(temp[i]==true){
        for(int j=0;j<nums.size();j++){
            temp[i+nums[j]]=true;
        }
    }
}
return temp[targetsum];
}
int main(){
   
if(canSum(7,{5,2,0})) cout<<"True"<<endl;
else cout<<"False"<<endl;
}