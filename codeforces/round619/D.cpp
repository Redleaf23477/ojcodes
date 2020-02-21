// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll R, C, len;

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
    cin >> R >> C >> len;
}

void run(vector<pair<ll,string>> &ans)
{
    // step 1 : s shape go down
    for(int r = 0; r < R; r++)
    {
        // horizontal
        string dir = (r%2 == 0? "R" : "L");
        if(C > 1)
        {
            if(len > C-1)
            {
                ans.emplace_back(C-1, dir);
                len -= C-1;
            }
            else
            {
                ans.emplace_back(len, dir);
                len = 0;
                return;
            }
        }
        // go down
        if(r != R-1)
        {
            ans.emplace_back(1, "D");
            len -= 1;
            if(len == 0) return;
        }
    }
    // step 2 : s shape reverse go up
    for(int r = R-1; r >= 0; r--)
    {
        // horizontal
        string dir = (r%2 == 0? "L" : "R");
        if(r != 0) dir = "UD" + dir;
        if(C > 1)
        {
            if(len > (C-1)*dir.size())
            {
                ans.emplace_back(C-1, dir);
                len -= (C-1)*dir.size();
            }
            else
            {
                if(len/dir.size() > 0)
                {
                    ans.emplace_back(len/dir.size(), dir);
                    len %= dir.size();
                }
                if(len > 0) ans.emplace_back(1, dir.substr(0, len));
                len = 0;
                return;
            }
        }
        // go up
        if(r != 0)
        {
            ans.emplace_back(1, "U");
            len -= 1;
            if(len == 0) return;
        }
    }
}

void process()
{
    if(len > 4*R*C - 2*R - 2*C) 
    {
        cout << "NO" << endl; return;
    }
    vector<pair<ll, string>> ans;
    run(ans);
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto x : ans) cout << x.first << " " << x.second << endl;
}

