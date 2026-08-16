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
int main(){
    int n;
    cout<<"Enter the number  : ";
    cin>>n;
    int power;
    cout<<"Enter power : ";
    cin>>power;
    cout<<n<<" ^ "<<power<<" = "<<power_(n,power)<<endl;
}