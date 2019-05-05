#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 2e5 + 100;
int Arr[maxn];

int main(){
    //freopen("in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",Arr+i);
    int *p = Arr,*q = Arr+n-1,r=0,key,cnt=0;
    string operation;
    while(p <= q && (*p > r || *q > r)){
        if(*p == *q && p!=q){
            int kr = r;
            int *tmp = p;
            string op1,op2;
            while( *p > kr && p<=q){
                kr = *p;
                op1 += 'L';
                p++;
            }
            p = tmp;
            kr = r;
            while( *q > kr && p<=q){
                kr = *q;
                op2 += 'R';
                q--;
            }
            if(op1.size() > op2.size()) operation += op1,cnt+=op1.size();
            else operation += op2,cnt+=op2.size();
            break;
        }
        int flag = -1;
        cnt++;
        if(*p > r) flag=0;
        if(*q > r){
            if((*q < *p ) || (flag == -1)) flag=1;
        }
        if(flag==1){
            operation+='R';
            r=*q;
            --q;
        }
        else if(flag==0) {
            operation+='L';
            r=*p;
            ++p;
        }
    }
    printf("%d\n%s\n",cnt,operation.c_str());
    return 0;
}
