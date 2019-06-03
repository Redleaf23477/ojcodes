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
    int T; cin >> T;
    while(T--)
    {
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
}

bool ok(int cut, int n)
{
    int tot = cut;
    for(int i = 0; i < cut; i++)
    {
        tot += tot+1;
    }
    return (n-tot <= tot+1);
}

void process()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        if(ok(i, n))
        {
            cout << i << endl; return;
        }
    }
}

