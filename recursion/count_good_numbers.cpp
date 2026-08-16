# include<bits/stdc++.h>
using namespace std;
int power_(int base,int power){
    int ans=1;
    while(power){
        if(power%2==1){
            ans*=base;
        }
        base=(base*base);
        power=power/2;
    }
    return ans;

}
int count(int len){
    int even_pos=(len+1)/2;
    int odd_pos=(len)/2;
    int even_ways=power_(5,even_pos);
    int odd_ways=power_(4,odd_pos);
    return even_ways*odd_ways;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<count(n)<<endl;
}