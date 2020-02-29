#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int base[10] = {10000,1000,100,10,1};
bool visite[19],tmp[19];

bool try_insert(int to_insert){
    if(visite[to_insert]) return 1;
    visite[to_insert] = 1;
    return 0;
}

bool cut(int a){
    int mod;
    while(a){
        mod = a%10;
        a/=10;
        if(visite[mod]) return 0;
        else visite[mod] = 1;
    }
    return 1;
}
        

int main(){
    int n;
    int s,x,a[5];
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        bool flag = 1;
        for(a[0]=0; a[0]<10; a[0]++){
            memset(visite,0,sizeof(visite));
            visite[a[0]] = 1;
            for(a[1]=0; a[1]<10; a[1]++){
                if(try_insert(a[1])) continue;
                for(a[2]=0; a[2]<10; a[2]++){
                    if(try_insert(a[2])) continue;
                    for(a[3]=0; a[3]<10; a[3]++){
                        if(try_insert(a[3])) continue;
                        for(a[4]=0; a[4]<10; a[4]++){
                            if(try_insert(a[4])) continue;
                            memcpy(tmp,visite,sizeof(visite));
                            x = 0;
                            for(int i=0; i<5; i++) x+=a[i]*base[i];
                            s = x*n;
                            if(cut(s)) 
                            {
                                printf("%05d / %05d = %d\n",s,x,n);
                                flag = 0;
                            }
                            memcpy(visite,tmp,sizeof(visite));
                            visite[a[4]] = 0;
                        }
                        visite[a[3]] = 0;
                    }
                    visite[a[2]] = 0;
                }
                visite[a[1]]= 0;
            }
        }
        if(flag) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
