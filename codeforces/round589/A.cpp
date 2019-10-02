//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int l, r;

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
    cin >> l >> r;
}

bool ok(int n)
{
    vector<bool> vis(10, false);
    stringstream ss; ss << n;
    string str; ss >> str;
    for(auto c : str)
    {
        int d = c-'0';
        if(vis[d] == true) return false;
        vis[d] = true;
    }
    return true;
}

void process()
{
    int ans = -1;
    for(int i = l; i <= r; i++) if(ok(i)) { ans = i; break; }
    cout << ans << endl;
}

