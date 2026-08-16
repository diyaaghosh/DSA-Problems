# include<bits/stdc++.h>
using namespace std;
int precendence(char ch){
    if(ch=='^')return 3;
    else if(ch=='*' || ch=='/')return 2;
    else if(ch=='+' || ch=='-')return 1;
    return -1;

}
bool is_operator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')return true;
    return false;
}
int main(){
    string exp;
    cout<<"Enter infix expression : ";
    cin>>exp;
    stack<string>st;
    string res="";
    int n=exp.size();
    for(int i=n-1;i>=0;i--){
        string ch="";
        ch+=exp[i];
        if(!is_operator(exp[i])){
            st.push(ch);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp=op1+ch+op2;
            st.push(temp);
        }
    }
    cout<<st.top()<<endl;

}