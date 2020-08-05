// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

const int MAXN=100000; // 1-base
const int MLG=17; //log2(MAXN)+1;
int pa[MLG+2][MAXN+5];
int dep[MAXN+5];
vector<int> G[MAXN+5];
void dfs(int x,int p=0){//dfs(root);
    pa[0][x]=p;
    for(int i=0;i<=MLG;++i)
        pa[i+1][x]=pa[i][pa[i][x]];
    for(auto &i:G[x]){
        if(i==p)continue;
        dep[i]=dep[x]+1;
        dfs(i,x);
    }
}
inline int jump(int x,int d){
    for(int i=0;i<=MLG;++i)
        if((d>>i)&1) x=pa[i][x];
    return x;
}

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
}

