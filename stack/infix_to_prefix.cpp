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

string infix_to_postfix(string exp){
    stack<char>st;
    string res="";
    for(auto ch:exp){
        if((ch>='a' && ch<='z')||(ch>='A' && ch<'Z') || (ch>='0' && ch<='9')){
            res+=ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precendence(st.top())>=precendence(ch)){
                res+=st.top();
                st.pop();
            }
            st.push(ch);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
   
    return res;
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
int main(){
    string exp;
    cout<<"Enter infix expression : ";
    cin>>exp;
    string postfix=infix_to_postfix(exp);
    cout<<"prefix Expresion : "<<postfix_to_prefix(postfix)<<endl;

}