#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;
long long gridTraveller(long long m,long long n){
    vector<vector<long long>>table(m+1,vector<long long>(n+1,0));
    table[1][1]=1;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            long long current=table[i][j];
            if(i+1<=m){
            table[i+1][j]+=current;
            }
            if(j+1<=n){
                  table[i][j+1]+=current;
            }
        }
    }
    return table[m][n];

}
int main(){
cout<<gridTraveller(1,1)<<endl;
cout<<gridTraveller(2,3)<<endl;
cout<<gridTraveller(3,2)<<endl;
cout<<gridTraveller(3,3)<<endl;
cout<<gridTraveller(18,18)<<endl;
}