#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;


struct FIND{
    int per;
    char act;
};

struct NODE{
    int hash,zero;
    int Line[9];
};


int fac[9];
void FacInit(void){
    fac[0] = 1;
    for(int i=1; i<9; i++) fac[i] = fac[i-1]*i;
    return;
}

int get_hash(int *arr){
    int cnt,hash=0;
    for(int i=0,index = 8; i<9; i++,index--){
        cnt = 0;
        for(int j=i+1; j<9; j++){
            if(arr[j] < arr[i]) cnt++;
        }
        hash += fac[index] * cnt;
    }
    return hash;
}

const int maxn = 1e7;
FIND way[maxn];
NODE st;
int visite1[maxn];
int visite2[maxn];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char Zmv[6] = "rldu";
char Fmv[6] = "lrud";

void PrintWay(const FIND &now){
    if(now.per > 0) PrintWay(way[now.per]);
    else return;
    printf("%c",way[now.per].act);
    return;
}

void bfs(){
    NODE now,next;
    int x,y,tx,ty;
    for(int i=0; i<9; i++) now.Line[i] = (i+2)%10;
    now.zero = 8;
    now.hash = 46233;
    visite1[now.hash] = -1;
    queue<NODE> ZList;
    ZList.push(st);
    //use visite1
    queue<NODE> FList;
    FList.push(now);
    //use visite2
    while(!FList.empty() && !ZList.empty()){
        now = FList.front();
        FList.pop();
        if(visite2[now.hash]){
            /*rebuild*/
            PrintWay(way[now.hash]);
            int k = visite2[now.hash];
            while(k > 0){
                printf("%c",way[k].act);
                k = way[k].per;
            }
            return;
        }
        x = now.zero/3, y = now.zero%3;
        for(int i=0; i<4; i++){
            next = now;
            tx = x + dir[i][1],ty = y + dir[i][0];
            if(tx < 0 && ty < 0 && tx > 2 && ty > 2) continue;
            next.zero = tx*3 + ty;
            swap(next.Line[next.zero],next.Line[now.zero]);
            next.hash = get_hash(next.Line);
            cout << next.hash << endl;
            if(!visite1[next.hash]){
                visite1[next.hash] = now.hash;
                way[next.hash].act = Fmv[i]; 
                way[next.hash].per = now.hash;
                FList.push(next);
            }
        }
        now = ZList.front();
        ZList.pop();
        if(visite1[now.hash]){
            /*rebuild*/
            PrintWay(way[now.hash]);
            int k = visite1[now.hash];
            while(k > 0){
                printf("%c",way[k].act);
                k = way[k].per;
            }
            return;
        }
        x = now.zero/3, y = now.zero%3;
        for(int i=0; i<4; i++){
            next = now;
            tx = x + dir[i][1],ty = y + dir[i][0];
            if(tx < 0 && ty < 0 && tx > 2 && ty > 2) continue;
            next.zero = tx*3 + ty;
            swap(next.Line[next.zero],next.Line[now.zero]);
            next.hash = get_hash(next.Line);
            cout << next.hash << endl;
            if(!visite2[next.hash]){
                visite2[next.hash] = now.hash;
                way[next.hash].act = Zmv[i]; 
                way[next.hash].per = now.hash;
                ZList.push(next);
            }
        }
    }
}






int main(){
    char tmp[30];
    freopen("in","r",stdin);
    FacInit();
    while(fgets(tmp,sizeof(tmp),stdin) != NULL){
        for(int i=0,index=0; i<30; i++){
            if(tmp[i] == 'x'){
                st.zero = index;
                st.Line[index++] = 0;
            }
            else if(tmp[i] != ' ') 
                st.Line[index++] = tmp[i] - '0';
        }
        int flag = 0;
        for(int i=0; i<9; i++){
            if(st.Line[i]){
                for(int j=i+1; j<9; j++){
                    if(st.Line[j] < st.Line[i] && st.Line[j]) flag++;
                }
            }
        }
        if(flag&1)
            printf("unsolvable\n");
        else{
            memset(visite2,0,sizeof(visite2));
            memset(visite1,0,sizeof(visite1));
            st.hash = get_hash(st.Line);
            visite2[st.hash] = -1;
            bfs();
        }
    }
    return 0;
}

