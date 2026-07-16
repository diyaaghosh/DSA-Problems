# include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=0;
            }
        }
         maxi=max(maxi,cnt);
        
        if(maxi%2==0){
            cout<<(maxi/2)<<endl;
        }
        else{
            cout<<(maxi/2)+1<<endl;
        }
    }
}