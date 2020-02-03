//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, m;
vector<string> s, t;

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
    s.resize(n), t.resize(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
}

void process()
{
    int T; cin >> T;
    while(T--)
    {
        ll x; cin >> x;
        x--;
        cout << s[x%n] << t[x%m] << endl;
    }
}

