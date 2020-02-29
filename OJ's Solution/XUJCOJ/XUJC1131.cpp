#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,people[4];
    cin >> n;
    while(n--)
    {
        for(int i=0; i<4; i++) cin >> people[i];
        sort(people,people+4);
        printf("%d\n",people[1]-people[0]==1? people[3]:people[0]);
    }
    return 0;
}
