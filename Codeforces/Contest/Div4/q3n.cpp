# include<iostream>
# include<vector>
# include<set>
# include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

     
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }

        vector<int> arr1;
        for(auto it:st){
            arr1.push_back(it);
        }

        int m = arr1.size();
        int ans = 1;

    
        for(int i=0;i<m;i++){
            int curr = arr1[i];
            int len = 1;

            for(int j=i+1;j<m;j++){
                if(arr1[j] == curr + 1){
                    curr = arr1[j];
                    len++;
                }
                else if(arr1[j] > curr + 1){
                    break;
                }
            }
            ans = max(ans, len);
        }

        cout<<ans<<endl;
        t--;
    }
}
