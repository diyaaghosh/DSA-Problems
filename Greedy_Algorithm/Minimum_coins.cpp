# include<iostream>
# include<vector>
# include<map>
# include<set>
# include<algorithm>
#include<stack>
#include<queue>
using namespace std;
 int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int cnt=0;
        while(amount!=0){
            for(int i=n-1;i>=0;i--){
                if(coins[i]<=amount){
                    while(coins[i]<=amount){
                        cout<<coins[i]<<" "<<amount<<endl;
                        amount-=coins[i];
                        cnt++;
                    }
                }
                if(i==0 && amount%coins[i]!=0)return -1;
            }
        }
        return cnt;
    }
int main(){
    int n;
    cout<<"Enter the number of different coins : ";
    cin>>n;
    cout<<"Enter the denominations of the coins : ";
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter the amount : ";
    cin>>amount;
    int cnt=coinChange(coins,amount);   
    cout<<"Minimum number of coins required is : "<<cnt<<endl;

}
