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
string postfix_to_prefix(string exp){
    int n=exp.size();
    stack<string>st;
    string res="";
    
    for(int i=0;i<n;i++){
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
            string temp=ch+op2+op1;
            st.push(temp);
        }
    }
    return st.top();
}
string prefix_infix(string exp){
    int n=exp.size();
    stack<string>st;
    string res="";
    
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
    return st.top();
}

int main(){
    string exp;
    cout<<"Enter postfix expression : ";
    cin>>exp;
    string prefix=postfix_to_prefix(exp);
    cout<<prefix_infix(prefix)<<endl;

}