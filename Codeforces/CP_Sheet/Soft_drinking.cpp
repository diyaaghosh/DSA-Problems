#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min(((k*l)/nl),min((c*d),p/np))/n<<endl;
}

// 1 7 4 5 5 8 3 2
// Copy
// Output
// 8
// Copy
// Answer
// 4
// Copy
// Checker Log
// wrong answer expected 4, found 8