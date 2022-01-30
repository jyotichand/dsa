#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["abc1"]=2;
    ourmap["abc2"]=3;
    ourmap["abc3"]=4;
    ourmap["abc4"]=5;
    ourmap["abc5"]=6;
    
    unordered_map<string,int> :: iterator it = ourmap.begin();
    while(it != ourmap.end()) // ourmap.end() means after last element also.
    {
        cout<<"key : "<<it->first <<"Value: "<<it->second<<endl;
        it++;
    }
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1=v.begin();
    while(it1 != v.end())
    {
        cout<< *it1 <<endl;
        it1++;
    }
    
    // find (this will return a iterator for us)
    unordered_map<string,int>::iterator it2=ourmap.find();
    // this will erase the it2,it2+1,it2+2,it2+3 locations of iterartor
    ourmap.erase(it2,it+4);
    /* in unordrered_map it won't make a lot of sense to erase iteratively but in vector it makes a lot of sense to use earse();
}
