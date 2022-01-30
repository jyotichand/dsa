#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a,int size)
{
    vector<int>output;
    unordered_map<int , bool> seen;
    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}
int main()
{
    int a[]={1,2,3,4,1,4,2,1,7,3,1,3,4,2,4,0,22};
    vector<int> output=removeDuplicates(a,17);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }
}
