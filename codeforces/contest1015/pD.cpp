//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, k, s;

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
    cin >> n >> k >> s;
}

void process()
{
    bool good = false;
    for(int i = 0; i < k && !good; i++)
    {
        ll x = k-i-1, y = s-i*(n-1)-x;
        if(0 < y && y <= n-1)
        {
//            cout << x << " " << y << " " << i << endl;
            good = true;
            vector<int> ans;
            for(int j = 0; j < i; j++)
            {
                if(j%2 == 0) ans.push_back(n);
                else ans.push_back(1);
            }
            int pos = (i%2 == 0? 1+y:n-y);
            ans.push_back(pos);
            for(int j = 0; j < x; j++)
            {
                if(pos < n) pos++;
                else pos--;
                ans.push_back(pos);
            }
            cout << "YES" << endl;
            for(auto x:ans) cout << x << " "; cout << endl;
        }
    }
    if(!good) cout << "NO" << endl;
}

