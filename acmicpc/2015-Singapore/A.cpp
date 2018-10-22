//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 220;

struct Node
{
    int r, c, idx;
};
bool operator < (const Node &lhs, const Node &rhs) 
{
    if(lhs.r != rhs.r) return lhs.r < rhs.r;
    if(lhs.c != rhs.c) return lhs.c < rhs.c;
    return lhs.idx < rhs.idx;
}

int n, sr, sc, len;
int dr[N], dc[N];
string str;
char grid[N][N];

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
    cin >> n >> str;
    len = str.size();
//    cout << "len = " << len << endl;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
        {
            cin >> grid[r][c];
            if(grid[r][c] == 'R') sr = r, sc = c;
        }
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == '<') dr[i] = 0, dc[i] = -1;
        else if(str[i] == '>') dr[i] = 0, dc[i] = 1;
        else if(str[i] == '^') dr[i] = -1, dc[i] = 0;
        else dr[i] = 1, dc[i] = 0;
    }
}

void process()
{
    map<Node, int> mp;
    int r = sr, c = sc, nr, nc, idx = 0, tim = 0;
    while(true)
    {
        // skip 
        for(int cnt = 0; ; cnt++, idx = (idx+1)%len)
        {
            if(cnt == len) { cout << 1 << endl; return; }
            nr = r+dr[idx], nc = c+dc[idx];
            if(grid[nr][nc] == '#') continue;
            break;
        }
//        cout << ".." << r << " " << c << " " << idx << " " << tim << endl;
        Node cur = (Node){r,c,idx};
        // check
        if(mp.count(cur) != 0)
        {
            cout << tim - mp[cur] << endl;
            return;
        }
        mp[cur] = tim++;
        r = nr, c = nc, idx = (idx+1)%len;
    }
}

