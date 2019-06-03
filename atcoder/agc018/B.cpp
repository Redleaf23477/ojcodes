//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 303;

int n, m;
int peo[N][N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> peo[i][j];
}

void process()
{
    int mn = N;
    int ptr[N] = {0};
    int cnt[N] = {0};
    bool shutdown[N] = {false};

    for(int i = 0; i < n; i++) cnt[peo[i][ptr[i]]]++;

    for(int t = 0; t < m; t++)
    {
        int mx = 0, idx = -1;
        for(int i = 1; i <= m; i++) 
        {
            if(cnt[i] > mx) mx = cnt[i], idx = i;
        }
        mn = min(mn, mx);
        cnt[idx] = 0;
        shutdown[idx] = true;
        if(t == m-1) break;
        for(int i = 0; i < n; i++)
        {
            if(shutdown[peo[i][ptr[i]]])
            {
                while(shutdown[peo[i][ptr[i]]]) ptr[i]++;
                cnt[peo[i][ptr[i]]]++;
            }
        }
    }

    cout << mn << endl;
}

