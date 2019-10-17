#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define prt(x) printf(#x " %d\n",x);

const int Scale = 26;
int main()
{
    string a,b;
    int number[150]= {0};
    int out[150] = {0};
    cin >> a >> b;
    int j=0,add=0,per=0;
    for(int i=a.size()-1; i>=0; i--,j++)
    {
        number[j] = a[i] + b[i] - 'a' - 'a' + add;
        add = number[j]/Scale;
        number[j]%=Scale;
    }
    if(add!=0) number[j++] = add;
    //prt(add);
    for(int i=0; i< j/2; i++)
        swap(number[i],number[j-1-i]);
    //for(int i=0; i<j; i++) printf("%c ",number[i] + 'a');
    //printf("\n");
    int index = 0;
    int flag = 0;
    if(a[0]=='a' || b[0]=='a') flag=1;
    for(int i=0; i<j; i++)
    {
        int individe = Scale*per + number[i];
        if(flag) 
            out[index++] = individe/2;
        else if(individe >= 2)
            out[index++] = individe/2,flag=1;
        per = individe%2;
    }
    for(int i=0; i<index; i++) printf("%c",'a'+out[i]);
    printf("\n");
    return 0;
}

        
