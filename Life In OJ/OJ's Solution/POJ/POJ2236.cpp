#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e3+100;
int x[maxn],y[maxn],f[maxn],s[maxn];
int N,d;

double contain(int id,int w){
    return (sqrt(pow(x[id] - x[w],2) + pow(y[id] - y[w],2)) <= d);
}

int fi(int id){
    if(id == f[id]) return id;
    else{
        return f[id] = fi(f[id]);
    }
}

void merge(int id){
    s[id] = 1;
    for(int i=1; i<=N; i++){
        if(s[i] && contain(id,i)){
            f[fi(i)]  = id;
        }
    }
    return;
}
            

int main(){
    //freopen("in","r",stdin);
    cin >> N >> d;
    for(int i=1; i<=N; i++){
        cin >> x[i] >> y[i];
        f[i] = i;
        s[i] = 0;
    }
    char act;
    while(cin >> act){
        int a,b; 
        if(act == 'O'){
            cin >> a;
            merge(a);
        }
        if(act == 'S'){
            cin >> a >> b;
            if(fi(a) == fi(b)) cout << "SUCCESS\n";
            else cout << "FAIL\n";
        }
    }
    return 0;
}


