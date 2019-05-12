#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string> 
#include <map>
using namespace std; 


int T,n,m;

struct Node{
    int x,y;
    string act;
    Node() :act("") {}
    bool operator == (const Node &other) const {
        return (other.x == x) && (other.y == y) && (other.act == act);
    }
    bool operator < (const Node &other) const{
        if(x == other.x){
            return other.y < y;
        }
        return x < other.x;
    }
};

struct line{
    Node first,second;
    bool operator < (const line &other) const{
        if(first == other.first)
            return second < other.second;
        return first < other.first;
    }
};
map<line,bool> visite;

char op[2] = {'U','R'};
int dir[2][2] = {{1,0},{0,1}};

bool bfs(){
    Node now,next;
    line cup;
    now.x = 0;
    now.y = 0;
    queue<Node> List;
    List.push(now);
    while(!List.empty()){
        now = List.front();
        List.pop();
        if(now.x == n && now.y == m){
            cout << now.act << endl;
            return false;
        }
        for(int i=0; i<2; i++){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            cout << "( " << now.x << " , " << now.y << " )" <<endl;
            cout << "( " << next.x << " , " << next.y << " )" <<endl;
            cup.first = now;
            cup.second = next;
            cout << visite[cup] << endl;
            if(!visite[cup]){
                visite[cup] = 1;
                cup.first = next;
                cup.second = now;
                visite[cup] = 1;
                next.act = now.act+op[i];
                cout << " insert = ( " << next.x << " , " << next.y << " )" <<endl;
                List.push(next);
            }
        }
    }
    return true;
}


int main(){
    map<char,int> dirx;
    map<char,int> diry;
    dirx['U'] = 1;
    diry['U'] = 0;
    dirx['R'] = 0;
    diry['R'] = 1;
    string tmp;
    scanf("%d",&T);
    while(T--){
        visite.clear();
        scanf("%d%d",&n,&m);
        cin >> tmp;
        int lon = tmp.size();
        int x=0,y=0;
        Node now,next;
        line cup;
        for(int i=0; i<lon; i++){
            now.x = x,now.y = y;
            next.x = x+dirx[tmp[i]],next.y = y+diry[tmp[i]];
            cup.first = now,cup.second = next;
            visite[cup] = 1;
            cup.first = next,cup.second = now;
            visite[cup] = 1;
            x = next.x,y = next.y;
            cout << "mark ( " << now.x << " , " << now.y << " )" <<endl;
            cout << "( " << next.x << " , " << next.y << " )" <<endl;
        }
        if(bfs()) cout << "impossible" << endl;
    }
    return 0;
}
