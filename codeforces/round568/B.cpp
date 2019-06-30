//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

string a, b;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> a >> b;
}

void process()
{
    bool good = true;
    size_t i, j;
    for(i = 0, j = 0; i < a.size() && j < b.size(); i++)
    {
        if(a[i] != b[j]) 
        {
            good = false;
            break;
        }

        if(i != a.size())
        {
            if(a[i] != a[i+1]) while(j < b.size() && b[j] == a[i]) j++;
            else j++;
        }
    }
    good &= (i == a.size() && j == b.size());
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

