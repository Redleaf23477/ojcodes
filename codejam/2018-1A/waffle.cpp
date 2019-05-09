//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 110;

int R, C, V, H;
ll arr[N][N];
ll sum[N][N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> C >> H >> V;
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
        {
            char ch; cin >> ch;
            if(ch == '@') arr[r][c] = 1;
            else arr[r][c] = 0;
            sum[r][c] = 0;
        }
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
        {
            sum[r][c] = arr[r][c] + sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1];
        }
}

void process()
{
    int blockNum = (V+1)*(H+1);
    if(sum[R][C] % blockNum != 0)
    {
        cout << "IMPOSSIBLE" << endl; return;
    }
    int avgrow = sum[R][C] / (H+1);
    int avgcol = sum[R][C] / (V+1);
    int avg = sum[R][C] / blockNum;

    // consider vertical first
    vector<int> rowcut;
    for(int r = 1; r <= R && rowcut.size() < H; r++)
    {
        if(rowcut.empty() && sum[r][C] == avgrow) rowcut.push_back(r);
        else if(!rowcut.empty() && sum[r][C] == sum[rowcut.back()][C] + avgrow) rowcut.push_back(r);
    }
    rowcut.push_back(R);

    /*
    cout << endl;
    for(auto r:rowcut) cout << r << " ";
    cout << endl;
    */

    if(rowcut.size() != H+1 || rowcut.back() != R) 
    {
        cout << "IMPOSSIBLE" << endl; return;
    }

    // consizer horizontal
    vector<int> colcut;
    for(int c = 1; c <= C && colcut.size() < V; c++)
    {
        if(colcut.empty() && sum[R][c] == avgcol) colcut.push_back(c);
        else if(!colcut.empty() && sum[R][c] == sum[R][colcut.back()] + avgcol) colcut.push_back(c);
    }
    colcut.push_back(C);

    if(colcut.size() != V+1 || colcut.back() != C) 
    {
        cout << "IMPOSSIBLE" << endl; return;
    }

    // check valid
    for(size_t i = 0; i < rowcut.size(); i++)
        for(size_t j = 0; j < colcut.size(); j++)
        {
            ll u = (i == 0? 0 : sum[rowcut[i-1]][colcut[j]]);
            ll l = (j == 0? 0 : sum[rowcut[i]][colcut[j-1]]);
            ll ul = (i != 0 && j != 0? sum[rowcut[i-1]][colcut[j-1]] : 0);
            ll block = sum[rowcut[i]][colcut[j]] - u - l + ul;
            if(block != avg) { cout << "IMPOSSIBLE" << endl; return; }
        }
    cout << "POSSIBLE" << endl;
}

