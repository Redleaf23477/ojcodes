// using Floyd Warshall
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 600;

int n, q;
int mpidx;
map<string, int> mp;
vector<int> G[N];
bool dp[N][N];

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
    mpidx = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        string a, is, worse, than, b;
        cin >> a >> is >> worse >> than >> b;
        if(mp.count(a) == 0) mp[a] = mpidx++;
        if(mp.count(b) == 0) mp[b] = mpidx++;
        int aidx = mp[a], bidx = mp[b];
        G[aidx].push_back(bidx);
        dp[aidx][bidx] = true;
    }
    // floyd warshall
    for(int k = 0; k < mpidx; k++)
        for(int i = 0; i < mpidx; i++)
            for(int j = 0; j < mpidx; j++)
                dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]); 
}


int check(string &a, string &b)
{
    int fact = 0, fake = 1, unknown = 2;
    int aidx, bidx;
    if(mp.count(a) == 0) return unknown;
    if(mp.count(b) == 0) return unknown;
    aidx = mp[a], bidx = mp[b];
    if(dp[aidx][bidx]) return fact;
    else if(dp[bidx][aidx]) return fake;
    else return unknown;
}

void process()
{
    string ans[3] = { "Fact", "Alternative Fact", "Pants on Fire" };
    while(q--)
    {
        string a, is, worse, than, b;
        cin >> a >> is >> worse >> than >> b;
        cout << ans[check(a, b)] << endl;
    }
}

