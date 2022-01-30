#include<iostream>
using namespace std;

// dynamic-programming (top-down or iterative approach)

int fibo_3(int n)
{
    int* ans= new int[n+1];
    
    ans[0]=0;
    ans[1]=1;
    
    for(int i=0;i<=n;i++)
    {
        ans[i]=ans[i-1]+abs[i-2];
    }
    return ans[n];
}

int fibo(int n)
{
    if(n<=1)
    {
        return n;
    }
    int a = fibo(n-1);
    int b = fibo(n-2);
    
    return a+b;
}

// memoization (bottom-up or recurrsive approach

int fibo_helper(int n,int* ans)
{
    if(n<=1)
    {
        return n;
    }
    if(ans[n]!= -1)
    {
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);
    
    ans[n]=a+b;
    
    return ans[n]=a+b;
    
}

int fibo_2(int n)
{
    int *ans= new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}

int main()
{
    int n;
    cin>>n;
    //cout<<fibo(n)<<endl;
    cout<<fibo_2(n)<<endl;
}
