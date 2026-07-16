#include <iostream>
#include <string>
using namespace std;



int main() {
    int t;
    cin >> t;
 
    for(int i=0;i<t;i++){
        int flag=0;
        string s;
        cin >> s;
        int n = s.length();
       
        for(int j=1;j<=n-1;j++){
            if(s[j] == s[j+1] || s[j]==s[j-1]){
              flag=1;
               
            }
        }
        if(flag==1){
            cout<<1<<endl;
        }
        else{
            cout<<n<<endl;
        }
        
    }
    return 0;
}