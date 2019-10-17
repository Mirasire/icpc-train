#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 363000;
const int D = 10;
char ope[5] = "rldu";
struct Node{
    int maze[9];
    //x = i/3 , y = i%3
    int zero,n; //n = centorNumber
    int h,g,f;
    void Load(void);
    bool operator <  (const Node &T) const{
        if(T.f != f) return T.f < f;
        return T.g < g; 
    }
};

struct FindWay{
    char operation;
    int per;
};

int get_index(int x,int y);
void PrintWay(FindWay &now);
int Heuristic(Node &T);
int cantor_number(const Node &T);

void Node::Load(){
    this->n = cantor_number(*this);
    this->h = Heuristic(*this); 
    f = h+g;
}

FindWay Way[maxn];
bool visite[maxn];
int plant[9];
int factor[9];
char tmp[40];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void FactorInit(void);

int cantor_number(const Node &T){
    int hash_number = 0;
    for(int i=0,index=8; i<9; i++,index--){
        int cnt = 0; 
        for(int j=i+1; j<9; j++){
            if(T.maze[j]  < T.maze[i]) cnt++;
        }
        hash_number += cnt*factor[index];
    }
    return hash_number;
}

int Heuristic(Node &T){
    int H = 0;
    for(int i=0; i<9; i++){
        if(0 == T.maze[i]) T.zero = i;
        else{
            int tx = i/3,ty = i%3; //数字当前所在的坐标
            int x = (T.maze[i] - 1)/3,y = (T.maze[i] - 1)%3;
            H += abs(x-tx) + abs(y-ty);
        }
    }
    return H;
}

void PrintWay(FindWay &now){
    if(now.	per > 0) PrintWay(Way[now.per]);
    else return;
    printf("%c",now.operation);
    return;
}

int get_index(int x,int y){
    return x*3+y;
}

void Astar(){
    memset(Way,0,sizeof(Way));
    memset(visite,0,sizeof(visite));
    Node  now,next;
    priority_queue<Node> List;
    for(int i=0; i<9; i++){
        if(plant[i] == 0) now.zero = i;
        now.maze[i] = plant[i];
    }
    now.g = 0;
    now.Load();
    visite[now.n] = 1;
    Way[now.n].per = -1;
    List.push(now);
    int ans = 46233; 
    while(!List.empty()){
        now = List.top();
        List.pop();
        if(now.n == ans){
            PrintWay(Way[now.n]);
            return;
        }
        int x = now.zero/3,y = now.zero%3;
        for(int i=0; i<4; i++){
            next  = now;
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            int nCur = get_index(nx,ny);
            swap(next.maze[nCur],next.maze[now.zero]);
            next.g = now.g + 1;
            //next.g = now.g+ 2;
            next.Load();
            if(!visite[next.n]){
                visite[next.n]= 1;
                Way[next.n].per = now.n;
                Way[next.n].operation = ope[i];
                List.push(next);
            }
        }
    }
}

int main(){
    FactorInit();
    while(fgets(tmp,sizeof(tmp),stdin) != NULL){
        for(int i=0,index=0; index<9; i++){
            if(tmp[i] == 'x') plant[index++] = 0;
            else if(tmp[i] != ' ') plant[index++] = tmp[i] - '0';
        }
        int nx = 0;
        for(int i=0; i<9; i++){
            int add = 0;
            if(plant[i]){
                for(int j=i+1; j<9; j++){
                    if(plant[j] < plant[i] && plant[j]){
                        add++;
                    }
                }
            }
            nx+=add;
        }
        if(nx%2) printf("unsolvable");
        else Astar();
        printf("\n");
    }
    return 0;
}

void FactorInit(){
    factor[0] = 1;
    for(int i=1; i<9; i++) factor[i] = factor[i-1]*i;
}
