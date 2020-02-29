//Why Cannot Pass
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int mod = 100000007;

int main()
{   
    int n,m,lon;
    string talk;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        string *word = new string[m];
        for(int i=0; i<m; i++) cin >> word[i];
        cin >> talk;
        lon = talk.size();
        int *UnderStanding = new int[lon+1];
        memset(UnderStanding,0,sizeof(int)*(lon+1));
        UnderStanding[0] = 1;
        for(int i=0; i<lon; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i+word[j].size() <= lon && talk.substr(i,word[j].size())==word[j])
                {
                    UnderStanding[word[j].size()+i] = (UnderStanding[i]+UnderStanding[word[j].size()+i])%mod;
                }
            }
        }
        printf("%d\n",UnderStanding[lon]);
        delete[]word;
        delete[]UnderStanding;
    }
    return 0;
}

