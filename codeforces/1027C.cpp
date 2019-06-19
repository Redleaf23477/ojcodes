//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<ll> side;

void init();
void process();

int main()
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
    map<ll, int> mp;
    side.clear();
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        ll x; cin >> x;
        if(mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
    for(auto x:mp)
    {
        while(x.second >= 2)
        {
            side.push_back(x.first);
            x.second -= 2;
        }
        /*
        if(x.second >= 4) 
        {
            side.push_back(x.first);
            side.push_back(x.first);
        }
        else if(x.second >= 2)
        {
            side.push_back(x.first);
        }
        */
    }
}

void process()
{
    ll la = side[0], lb = side[1];
    for(int i = 1, j = 2; j < side.size(); i++, j++)
    {
        if( (la*la+lb*lb)*side[i]*side[j] > (side[i]*side[i]+side[j]*side[j])*la*lb )
        {
            la = side[i], lb = side[j];
        }
    }
    cout << la << " " << la << " " << lb << " " << lb << endl;
}

