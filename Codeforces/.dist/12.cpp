#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n;
        cin>>k;
        if (k <= (2 * n - 2) * 2) {
            cout << (k + 1) / 2 << "\n";
        } else {
            cout <<  k / 2 + 1 << "\n";
        }
    }
    }
