#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 2e5+100;
int arr[maxn];

int main(){
    int k,cnt=0,key;
    string operation;
    scanf("%d",&k);
    for(int i=0; i<k; i++) scanf("%d",arr+i);  
    int p = 0, q = k-1,r = arr[0] > arr[k-1] ? k-1 : 0;
    while((arr[p] >= arr[r] || arr [q] >= arr[r]) && (p <= q)){
        int flag = -1;
        key = r;
        cnt++;
        if(arr[p] >= arr[key])
            flag=1,r=p;
        if(arr[q] >= arr[key]){
            if(flag==1 && arr[q] < arr[p])
                flag=0,r=q;
            else if(flag==-1)
                flag=0,r=q;
        }
        if(flag) p++,operation+='L';
        else q--,operation+='R';
    }
    printf("%d\n%s\n",cnt,operation.c_str());
    return 0;
}
