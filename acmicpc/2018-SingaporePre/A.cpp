//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 110;

int n;
string chess[N];
string want;

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
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++)
    {
        chess[i] = str.substr(i*n, n);
    }
    want = "ICPCASIASG";
}

bool legal(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

int dr[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dc[] = {-2, 2, -2, 2, -1, 1, -1, 1};
bool dfs(int r, int c, int idx)
{
    if(idx == want.size()) return true;
    bool found = false;
    for(int d = 0; d < 8 && !found; d++)
    {
        int nr = r+dr[d], nc = c+dc[d];
        if(legal(nr, nc) && chess[nr][nc] == want[idx])
            found = dfs(nr, nc, idx+1);
    }
    return found;
}


void process()
{
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
        {
            if(chess[r][c] == want[0] && dfs(r, c, 1))
            {
                cout << "YES" << endl; return;
            }
        }
    cout << "NO" << endl;
}

