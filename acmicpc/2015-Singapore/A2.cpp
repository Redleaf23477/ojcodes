//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define r first
#define c second

const int N = 202;

int n;
string str;
char grid[N][N];
P seq[2*N*N*N];
int fail[2*N*N*N];

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

int dr(char ch)
{
    if(ch == '^') return -1;
    if(ch == 'v') return 1;
    return 0;
}
int dc(char ch)
{
    if(ch == '<') return -1;
    if(ch == '>') return 1;
    return 0;
}

void init()
{
    cin >> n >> str;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'R') seq[0].r = i, seq[0].c = j;
        }
}

void kmp_fail(P *s,int len,int *fail){
    int id=-1;
    fail[0]=-1;
    for(int i=1;i<len;++i){
        while(~id&&s[id+1]!=s[i])id=fail[id];
        if(s[id+1]==s[i])++id;
        fail[i]=id;
    }
}

void process()
{
    for(int i = 1, idx = 0; i < 2*N*N*N; i++)
    {
        int nr, nc, cnt = 0;
        do{
            nr = seq[i-1].r + dr(str[idx]), nc = seq[i-1].c + dc(str[idx]);
            idx = (idx+1)%str.size();
            if(++cnt == str.size()) { cout << 1 << endl; return; }
        } while(grid[nr][nc] == '#');
        seq[i].r = nr, seq[i].c = nc;
    }
    kmp_fail(seq+N*N*N, N*N*N, fail);
//    for(int i = 0; i < 30; i++)
//        cout << i << " : " << seq[i].r << " " << seq[i].c << " " << fail[i] << endl;
    int tmp = N*N*N-1;
    cout << tmp-fail[tmp] << endl;
}

