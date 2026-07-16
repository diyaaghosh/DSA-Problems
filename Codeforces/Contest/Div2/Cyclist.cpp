# include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<deque>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,p,m;
        cin>>n>>k>>p>>m;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k==p && n==k){
            cout<<(m/arr[p-1])<<endl;
             continue;
        }
         else{
        deque<int>q;
        for(int i=0;i<n;i++){
            q.push_back(i);
        }
       
        int ans=0;
        while(m>0){
            int ind=-1;
            for(int i=0;i<min(k,(int)q.size());i++){
                if(q[i]==p-1){
                    ind=i;
                    break;
                }
            }
            // win card present in the range
            if(ind!=-1){
                if(m<arr[p-1])break;
                m-=arr[p-1];
                ans++;
                 q.erase(q.begin()+ind);
                 q.push_back(p-1);
            }
            else{
               // win card is not present in the range then we just choose the min element in the queue
                int min_ind=0;
                for(int i=1;i< min(k,(int)q.size());i++){
                if(arr[q[min_ind]]>arr[q[i]]){
                    min_ind=i;
                }
            }
                
                    if(m<arr[q[min_ind]]){
                        break;
                    }
                    m-=arr[q[min_ind]];
                    int erased_element=q[min_ind];
                    q.erase(q.begin()+min_ind);
                     q.push_back(erased_element);

                }
                  
            }
              cout<<ans<<endl; 
            }
        
        
        }

      
    }
    
