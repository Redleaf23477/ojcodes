//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> arr;

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
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; arr[i][j]--;
        }
    }
}

int run(vector<int> &col, int c)
{
    vector<int> goodShift(n, 0);
    for(int r = 0; r < n; r++)
    {
        if(col[r] >= n*m || col[r]%m != c) continue;
        int correct_pos = col[r]/m;
        goodShift[(r-correct_pos+n)%n]++;
    }
    int ans = n;
    for(int i = 0; i < n; i++)
    {
        ans = min(ans, i+n-goodShift[i]);
    }
    return ans;
}

void process()
{
    ll cnt = 0;
    for(int c = 0; c < m; c++)
    {
        vector<int> col(n);
        for(int r = 0; r < n; r++)
            col[r] = arr[r][c];
        cnt += run(col, c);
    }
    cout << cnt << endl;
}

