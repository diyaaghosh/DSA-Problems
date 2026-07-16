# include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    string str;
    cin>>str;
    int cnt=0;
    int n=str.size();
    map<int,int>mpp;
    int last_ind=-1;
    int first_ind=-1;
    for(int i=0;i<n;i+=1){
        if(str[i]=='1'){
            first_ind=i;
            break;
        }
    }
    for(int i=0;i<n;i+=1){
        if(str[i]=='1'){mpp[i]=1;
        last_ind=i;
        }
        else mpp[i]=0;
    }
    
    for(int i=first_ind;i<=last_ind;i++){
      
       if(mpp.find(i)!=mpp.end() && mpp[i]==0)cnt+=1;
    }
    cout<<cnt<<endl;
    }
}