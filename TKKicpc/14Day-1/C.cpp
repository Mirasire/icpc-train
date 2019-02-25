#include <iostream>
#include <queue>
using namespace std;

#define N 200005

bool HaveStep[N] = {0};

bool Jude(int x)
{
    if(x>=0 && x<=N) return 1;
    return 0;
}

struct Node
{
    int x;
    int step;
};

typedef Node NODE;

int BfsLenth(int in,int Target)
{
    NODE st,next,now;
    st.step=0;
    st.x=in;
    queue<NODE> link;
    link.push(st);
    while(!link.empty())
    {
        now = link.front();
        link.pop();
        if(now.x == Target) return now.step;
        next.x = now.x-1;
        next.step = now.step+1;
        if(Jude(next.x) && !HaveStep[next.x]) HaveStep[next.x] = 1,link.push(next);
        next.x = now.x+1;
        if(Jude(next.x) && !HaveStep[next.x]) HaveStep[next.x] = 1,link.push(next);
        next.x = now.x << 1;
        if(Jude(next.x) && !HaveStep[next.x]) HaveStep[next.x] = 1,link.push(next);
    }
    return 0;
}
int main()
{
    int M,K;
    cin >> M >> K;
    HaveStep[M] = 1;
    if(M>K) cout << M-K;
    else cout << BfsLenth(M,K);
    return 0;
}
