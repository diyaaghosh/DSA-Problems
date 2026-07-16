# include<iostream>
# include<vector>
# include<set>
# include<algorithm>
using namespace std;

int main(){
   long long t;
    cin>>t;
    while(t){
       long long n,m,h;
        cin>>n>>m>>h;
        vector<long long>arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<long long>original(n);
        for(long long i=0;i<n;i++){
            original[i]=arr[i];
        }
         
        vector<long long>increment(n,0);
        vector<vector<int>> ops(m, vector<int>(2));
       
        for (long long i = 0; i < m; i++) {
            cin >> ops[i][0] >> ops[i][1];
        }
        
        for (long long i = 0; i < m; i++) {
            long long index = ops[i][0]-1;
            long long val = ops[i][1];
            
            increment[index] += val; 

            if (arr[index] + increment[index] > h) {
                
               fill(increment.begin(), increment.end(), 0);
            }
        }
        
          for (long long i = 0; i < n; i++)
            cout << original[i] + increment[i] << " ";
        cout << "\n";
    
     
        t--;
    }
}