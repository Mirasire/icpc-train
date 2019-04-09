#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define prt(x) printf(#x " %d\n",x);
const int maxn = 2*1e5+100;
int number[maxn]= {0};
int out[maxn] = {0};
const int Scale = 26;
int main()
{
    int ll;
    cin >> ll;
    string a,b;
    cin >> a >> b;
    int j=0,add=0,per=0;
    for(int i=ll-1; i>=0; i--,j++)
    {
        number[j] = a[i] + b[i] - 'a' - 'a' + add;
        add = number[j]/Scale;
        number[j]%=Scale;
    }
    if(add!=0) number[j++] = add;
    int end = j/2;
    for(int i=0; i< end; i++)
        swap(number[i],number[j-1-i]);
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
