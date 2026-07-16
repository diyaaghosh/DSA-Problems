# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>arr(n,"");
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(auto it:arr){
        if(it=="Tetrahedron")cnt+=4;
        else if(it=="Cube")cnt+=6;
        else if(it=="Octahedron")cnt+=8;
        else if(it=="Dodecahedron")cnt+=12;
        else if(it=="Icosahedron")cnt+=20;
        
    }
    cout<<cnt<<endl;
}