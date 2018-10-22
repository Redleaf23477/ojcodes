// 
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    int n; cin >> n;
    int ans = 0;
    while(n--)
    {
        int x, y; cin >> x >> y;
        ans = max(ans, abs(y+x));
    }
    cout << ans << endl;
}

