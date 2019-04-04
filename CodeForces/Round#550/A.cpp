#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    int n;
    scanf("%d ",&n);
    char str[1000];
    while(n--)
    {
        int arr[1000] = {0};
        int letter[26] = {0};
        scanf(" %s",str);
        int lon = strlen(str);
        int flag = 1;
        int key,cnt=0;
        for(int i=0; i<lon&&flag; i++)
        {
            key = str[i] - 'a';
            if(!letter[key]) letter[key] = 1,arr[cnt++] = key;
            else flag = 0;
        }
        //cout << "flag " << flag << endl;
        if(flag)
        {
            int jude = 1;
            sort(arr,arr+cnt);
            for(int j=1; j<lon&&jude; j++)
            {
                if(arr[j]-arr[j-1] != 1) jude = 0;
            }
            if(jude) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
