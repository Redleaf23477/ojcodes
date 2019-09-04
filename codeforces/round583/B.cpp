//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll b, g, n;

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
    cin >> b >> g >> n;
}

void process()
{
    set<pair<int,int>> s;
    for(int i = 0; i <= min(b, n); i++)
    {
        int j = n - i;
        if(j <= g) s.insert(make_pair(i, j));
    }
    for(int i = 0; i < min(g, n); i++)
    {
        int j = n-i;
        if(j <= b) s.insert(make_pair(j, i));
    }
    cout << s.size() << endl;
}

