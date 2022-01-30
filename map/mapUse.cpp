#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> ourMap;
    //insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"]=2;
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;
    
    //cout<<ourMap.at("ghi")<<endl;
    cout<<"size :"<<ourMap.size()<<endl;
    cout<<ourMap["ghi"]<<endl;
    cout<<"size :"<<ourMap.size()<<endl;
    if(ourMap.count("ghi")>0)
       {
           cout<<"ghi is present"<<endl;
       }
       ourMap.erase("ghi");
       cout<<"size :"<<ourMap.size()<<endl;
       
}
