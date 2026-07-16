// #include<iostream>
// using namespace std;
// int main(){
//     int t ;
//     cin>>t;
//     for(int i=0;i<t;i++){
//        long long n;
//         cin>>n;
//        long long a[n];
//        long long b[n]={0};
      
        
//         for(int j=0;j<n;j++){
//             cin>>a[j];}
//             b[a[0]]=1;
//             int flag=1;
//             for(int j=1;j<n;j++){
//            if(b[a[j]+1]!=1 && b[a[j]-1]!=1){
         
//             flag=0;
//             break;
//            }
//            else{
//             b[a[j]]=1;
//            }
            
//         }
//         if(flag==1){
//         cout<<"YES"<<endl;}
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
// }

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
       int a[n];
        unordered_set<long long> b; // To store visited numbers

        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        b.insert(a[0]);
        bool flag = true;

        for (int j = 1; j < n; j++) {
            if (b.find(a[j] + 1) == b.end() && b.find(a[j] - 1) == b.end()) {
                flag = false;
                break;
            }
            b.insert(a[j]);
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
