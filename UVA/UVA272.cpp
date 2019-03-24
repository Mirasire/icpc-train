#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char a,q=0;
    while((a = getchar()) != EOF)
    {
        if(a=='"')
        {
            printf("%s",q? "''" : "``");
            q = !q;
        }
        else printf("%c",a);
    }
    return 0;
}
