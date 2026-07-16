# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=1;
    int total_sum=sum;
    int height=1;
    int i=1;
    while(n>=total_sum){
        
        height+=1;
        i+=1;
        sum=(i*(i+1))/2;
        total_sum+=sum;
    }
    
    cout<<height-1<<endl;


}