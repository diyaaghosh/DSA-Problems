# include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
int n=s.size();
int low=0;
int high=n-1;
while(low<=high){
    if(s[low]!=s[high]){
        return false;
    }
    low+=1;
    high-=1;
}
return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        // 00 , 11 => palindrome,01 , 10 => not palindrome
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt2+=1;
            else cnt1+=1;

        }
        if((cnt1==1 && (s[0]=='0' || s[n-1]=='0')) || (cnt2==1 && (s[0]=='1' || s[n-1]=='1'))){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }

    }
}