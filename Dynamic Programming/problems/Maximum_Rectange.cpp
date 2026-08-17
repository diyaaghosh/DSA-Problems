#include<bits/stdc++.h>
using namespace std; int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
int solve(vector<vector<char>>&mat){
int n=mat.size();
int m=mat[0].size();
vector<int>arr(m,0);
int max_area=0;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]=='0')arr[j]=0;
        else arr[j]++;
        
    }
    max_area = max(max_area, largestRectangleArea(arr));
}
return max_area;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int m;
    cout<<"Enter m : ";
    cin>>m;
    vector<vector<char>>mat(n,vector<char>(m,'0'));
    cout<<"Enter the elemets : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    cout<<"maximum rectangle area : "<<solve(mat)<<endl;
}