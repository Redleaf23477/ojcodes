//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 505;

int n;
string ans;
string oppo[N];
ll cnt[3][N];

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
    size_t mxlen = 0;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++)
    {
        cin >> oppo[i];
        mxlen = max(mxlen, oppo[i].size());
        for(size_t j = 0; j < oppo[i].size(); j++)
        {
            if(oppo[i][j] == 'R') cnt[0][j]++;
            else if(oppo[i][j] == 'S') cnt[1][j]++;
            else cnt[2][j]++;
        }
    }
}

void process()
{
    ans.clear();
    bool ok = true;
    vector<bool> lose(n, false);
    for(int i = 0; ok; i++)
    {
        int cntR = 0, cntS = 0, cntP = 0;
        for(int p = 0; p < n; p++)
        {
            if(lose[p]) continue;
            char ch = oppo[p][i%oppo[p].size()];
            if(ch == 'R') cntR++;
            if(ch == 'S') cntS++;
            if(ch == 'P') cntP++;
        }

        if(cntR == 0 && cntS == 0 && cntP == 0) break;
        else if(cntR && cntS && cntP) ok = false;
        else if(cntR && cntS) ans.push_back('R');
        else if(cntR && cntP) ans.push_back('P');
        else if(cntS && cntP) ans.push_back('S');
        else if(cntR) ans.push_back('P');
        else if(cntS) ans.push_back('R');
        else ans.push_back('S');

        for(int p = 0; p < n; p++)
        {
            if(lose[p]) continue;
            char ch = oppo[p][i%oppo[p].size()];
            if(ch == 'R' && ans.back() == 'P') lose[p] = true;
            if(ch == 'S' && ans.back() == 'R') lose[p] = true;
            if(ch == 'P' && ans.back() == 'S') lose[p] = true;
        }
    }
    if(ok) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}

