#include<iostream>
using namespace std;

void reverseStringWordWise(char input[]) {
    // Write your code here
    
    
    int i, j, index, startIndex, endIndex;
    
    int len=0;
    for(int i=0;input[i]!='\0';i++)
    {
        len++;
    }
    char revstr[len];
    index = 0;
    endIndex = len - 1;
    
    for(i = len - 1; i > 0; i--)
    {
        if(input[i] == ' ')
        {
            startIndex = i + 1;
            
            for(j = startIndex; j <= endIndex; j++)
            {
                revstr[index] = input[j];
                index++;
            }
            revstr[index++] = ' ';
            endIndex = i - 1;
        }
    }
    for(i = 0; i <= endIndex; i++)
    {
        revstr[index] = input[i];
        index++;
    }
    revstr[index] = '\0';
    for(int i=0;i<len;i++)
    {
        input[i]=revstr[i];
    }
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

