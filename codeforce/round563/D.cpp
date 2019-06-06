//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, k, sz;
vector<bool> cand;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> k;
    sz = 1<<n;
    cand.resize(1<<n, true);
    cand[0] = false;
    if(k < sz) cand[k] = false;
}

ll foo(ll n)
{
    ll sum = 0;
    for(ll i = 1; i < n; i++)
    {
        sum += sum+i;
    }
    return sum + n;
}

/*
void print(int i, vector<ll> &ans)
{
    if(i == 0) 
    {
        cout << ans[0] << " "; return;
    }
    print(i-1, ans);
    cout << ans[i] << " ";
    print(i-1, ans);
}
*/

void process()
{
    vector<ll> ans;
    vector<ll> fix;
    ll cidx = 1;
    while(cidx < cand.size())
    {
        if(cand[cidx] == false) 
        {
            cidx++; continue;
        }
        ans.push_back(cidx);
        fix.insert(fix.end(), fix.begin(), fix.end());
        for(size_t i = fix.size()/2; i < fix.size(); i++) 
        {
            fix[i] ^= cidx;
            if(fix[i] < sz) cand[fix[i]] = false;
            if((fix[i]^k) < sz) cand[fix[i]^k] = false;
        }
        fix.push_back(cidx);
        cand[cidx] = false;
        if((cidx^k) < sz) cand[cidx^k] = false;
        cidx++;
    }
    if(ans.size() == 0) cout << 0 << endl;
    else
    {
        ll anssz = foo(ans.size());
        cout << anssz << endl;
        vector<int> seq;
        for(size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
            for(auto x:seq) cout << x << " ";
            seq.push_back(ans[i]);
            seq.insert(seq.end(), seq.begin(), seq.end()-1);
        }
        cout << endl;
    }
}

