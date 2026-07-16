# include<bits/stdc++.h>
using namespace std;
bool isgood(long long x){
    vector<int>hash(10,0);
    int cnt=0;
   while(x){
    int rem=x%10;
    if(hash[rem]==0){
        cnt++;
        hash[rem]=1;
    }
    x=x/10;

   }
   return cnt<=2;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        bool flag=false;
        long long p=2*x;
        
        // while(!flag){
        //     if(isgood(p)  && isgood(p/x)){
        //         flag=true;
        //         break;
        //     }
        //     p+=x;
        // }
        // cout<<p/x<<endl;
        for(long long i=2;i<=100000000;i+=1){
            if(isgood(i) && isgood(x*i)){
                cout<<i<<endl;
                break;
            }
        }
     
    }
}