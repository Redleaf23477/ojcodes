//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

ll vn, en;
vector<ll> seq;

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
    cin >> vn >> en;
    vector<ll> G[N];
    for(int i = 0; i < en; i++)
    {
        ll a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back((b-a+vn)%vn);
        G[b].push_back((a-b+vn)%vn);
    }
    for(int i = 0; i < vn; i++)
    {
        sort(G[i].begin(), G[i].end());
        seq.push_back(G[i].size());
        for(auto d:G[i]) seq.push_back(d);
    }
    seq.insert(seq.end(), seq.begin(), seq.end());
}

void process()
{
    vector<ll> fail(seq.size());
    fail[0] = -1;
    for(ll i = 1, f = -1; i < fail.size(); i++)
    {
        while(f > -1 && seq[f+1] != seq[i]) f = fail[f];
        if(seq[f+1] == seq[i]) f++;
        fail[i] = f;
    }
    for(auto x:fail)
    {
        if(x == seq.size()/2) 
        {
            cout << "Yes" << endl; return;
        }
    }
    cout << "No" << endl;
}

