#include<iostream>
using namespace std;

#include<stack>

bool isBalanced(string expression)
{
    stack<char> stk;
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]=='(')
        {
            stk.push(expression[i]);
        }
        else if(expression[i]==')')
        {
            if(stk.empty())
            {
                return false;
            }
            char topChar=stk.top();
            stk.pop();
            if(expression[i]==')' && topChar=='(')
            {
                continue;
            }
            else{
                return false;
            }
        }
    }
    return stk.empty();
}
int main()
{
    string str;
    str ="(a+b)(";
    cout<<isBalanced(str)<<endl;
}
