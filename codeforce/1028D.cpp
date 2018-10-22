//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll MOD = 1e9+7;
set<int> buy, unknown, sell;

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
}

int minElement(set<int> &s) 
{
    return *s.begin();
}
int maxElement(set<int> &s)
{
    set<int>::iterator it = s.end();
    it--;
    return *it;
}

void process()
{
    int q; cin >> q;
    ll ans = 1;
    string cmd; int val;
    while(q--)
    {
        cin >> cmd >> val;
        if(ans == 0) continue;
        if(cmd.size() == 3)  // ADD
        {
            if(!buy.empty() && val <= maxElement(buy))
            {
                buy.insert(val);
            }
            else if(!sell.empty() && val >= minElement(sell))
            {
                sell.insert(val);
            }
            else
            {
                unknown.insert(val);
            }
        }
        else                 // ACCEPT
        {
            if(!buy.empty() && val == maxElement(buy))
            {
                buy.erase(val);
                for(auto x:unknown)
                    sell.insert(x);
                unknown.clear();
            }
            else if(!sell.empty() && val == minElement(sell))
            {
                sell.erase(val);
                for(auto x:unknown)
                    buy.insert(x);
                unknown.clear();
            }
            else if(unknown.find(val) != unknown.end())
            {
                auto vit = unknown.find(val);
                for(auto it = unknown.begin(); it != vit; it++)
                    buy.insert(*it);
                vit++;
                for(auto it = vit; it != unknown.end(); it++)
                    sell.insert(*it);
                unknown.clear();
                ans = ans*2%MOD;
            }
            else
                ans = 0;
        }
    }
    if(!unknown.empty()) ans = ans*(unknown.size()+1)%MOD;
    cout << ans << endl;
}

