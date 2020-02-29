#include <iostream>
#include <ctring>
using namespace std;

int base[10] = {1,2,3,4,5,6,7,8,9};
int n;
int tmp[12],old[12];
int b[12];
int get_h(){
    int h=0;
    for(int i=1; i<n; i++){
        if(tmp[i] != tmp[i-1]+1) h++;
    }
    return h;
}

bool out(int *arr){
    for(int i=0; i<n; i++){
        if(arr[i] !=  base[i]) return false;
    }
    return true;
}


bool dfs(int deep,int maxd){
    if(deep*3 + get_h() > maxd) return false;
    if(out(tmp)) return true;
    for(int i=0; i<n; i++){
        for(int j=i; i<n; j++){
            //----i--cutcut---j-----
            memcpy(old,tmp,sizeof(int)*n);
            int cnt = 0;
            for(int k=0; k<n; k++)
                if(k < i || k > j) b[cnt++] = tmp[k];
            //instert
            for(int k=0; k<cnt; k++){
                int cnt2 = 0;
                for(int t=0; t<k; t++) tmp[cnt2++] = b[t];
                for(int t=i; t<=j; t++) tmp[cnt2++] = old[t];
                for(int t=k; t<cnt; t++) tmp[cnt2++] = b[t];

                return dfs(deep+1,maxd);
                //dfs
                memcpy(tmp,old,sizeof(int)*n);
            }
        }
    }
    return false;
}


int main(){
    int kase = 0;
    while(scanf("%d",&n) != EOF){
        if(n==0) break;
        for(int i=0; i<n; i++) scanf("%d",tmp+i);
        printf("Case %d: ",++kase);
        int maxd;
        for(maxd=0; maxd<n; maxd++){
            if(dfs(0,maxd)) break;
        }
        printf("%d\n",maxd);
    }
    return 0;
}
