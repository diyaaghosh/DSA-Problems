# include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
     vector<pair<int,int>> ops;
  vector<pair<int,int>> ops;

        // First phase
        for (int i = 1; i <= n - 2; i++) {
            ops.push_back({i, n});
        }

        // Second phase
        int cur = n;
        for (int i = n - 1; i >= 2; i--) {
            ops.push_back({cur, i});
            cur = (cur + i + 1) / 2; // ceil((cur+i)/2)
        }

        cout << 2 << '\n';  // minimum possible final value

        for (auto &[a, b] : ops) {
            cout << a << ' ' << b << '\n';
        }

    }
    
    
    

