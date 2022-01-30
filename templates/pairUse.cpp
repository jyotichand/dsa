#include<iostream>
#include"pair.cpp"

using namespace std;

int main()
{
//    Pair<int,double> p1;
//    p1.setX(10);
//    p1.setY(20.34);
//
//    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair <Pair<int,int>,int> p2;
    p2.setY(10);
    Pair<int,int> p4;
    p4.setX(15);
    p4.setY(16);
    p2.setX(p4);
    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY();
}
