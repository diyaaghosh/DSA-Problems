# include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>arr(n,0);
        for(long long i=0;i<n;i+=1){
            cin>>arr[i];
        }
        if (n == 1) {
            cout << "Yes\n";
            continue;
        }
        int flag=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>=arr[i+1]){
                flag=0;
                break;
            }
        }
        if(flag==1){cout<<"Yes"<<endl;
            continue;
        }
        flag=1;
        int curr=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]<curr){
                flag=0;
                break;
            }
            else if(arr[i]!=curr){
                arr[i+1]=arr[i+1]+(arr[i]-curr);
                arr[i]=curr;
                
            }
            curr++;
        }
        if(flag && arr[n-2]>=arr[n-1]){
            flag=0;
        }
        if(flag==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}