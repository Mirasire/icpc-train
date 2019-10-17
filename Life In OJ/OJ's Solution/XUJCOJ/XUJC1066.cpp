#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 2e5;
char str[maxn];

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string out;
        scanf(" %[^\n]",str);
        int lon = strlen(str);
        for(int i=lon-1; i>0; i--){
            if(str[i-1] == ' ' && str[i] != ' ') out = (char)toupper(str[i]) + out;
        };
        if(str[0] != ' ') out = (char)toupper(str[0])+out;
        printf("%s\n",out.c_str());
    }
    return 0;
}
