# include<bits/stdc++.h>
using namespace std;
int precendence(char ch){
    if(ch=='^')return 3;
    else if(ch=='*' || ch=='/')return 2;
    else if(ch=='+' || ch=='-')return 1;
    return -1;

}
int main(){
    string exp;
    cout<<"Enter infix expression : ";
    cin>>exp;
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
    cout<<"Postfix Expression : "<<res<<endl;

}