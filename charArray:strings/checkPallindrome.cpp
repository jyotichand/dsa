#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]){
    
    int n=0;
    for(int i=0;str[i]!='\0';i++){
        n++;
    }
    
    int l = 0;
    int h = n- 1;
    
    
    while (h >= l)
    {
        if (str[l] != str[h])
            return false;
        
        
        l++;
        h--;
    }
    
    return true;
    
}


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}
