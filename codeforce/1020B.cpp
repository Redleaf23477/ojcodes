//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1010;

int n;
int nxt[N];

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
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> nxt[i];
}

int run(int s)
{
    vector<bool> vis(n+1, 0);
    while(vis[s] == false)
    {
        vis[s] = true;
        s = nxt[s];
    }
    return s;
}

void process()
{
    for(int i = 1; i <= n; i++)
    {
        cout << run(i) << " ";
    }
    cout << endl;
}

