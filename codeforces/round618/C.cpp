// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
vector<ll> arr;

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
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    vector<ll> bucket[64];
    for(auto x : arr)
    {
        for(int i = 0; i < 64; i++)
        {
            if((x>>i)&1) bucket[i].push_back(x);
        }
    }
    ll first = -7122;
    for(int i = 63; i >= 0; i--)
    {
        if(bucket[i].size() == 1) 
        {
            first = bucket[i].front();
            break;
        }
    }
    if(first != -7122) cout << first << " ";
    for(auto x : arr)
    {
        if(x == first)
        {
            first = -7122;
            continue;
        }
        cout << x << " ";
    }
    cout << endl;
}
