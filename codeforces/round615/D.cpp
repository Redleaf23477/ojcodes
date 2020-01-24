//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, x;

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
    cin >> n >> x;
}

void process()
{
    ll num;
    vector<int> cnt(x, 0);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    // pair first : cnt of rem
    // pair second : rem
    for(int i = 0; i < n; i++)
    {
        cin >> num; num %= x;
        cnt[num]++;
        ll now = i%x, need = i/x+1;
        if(cnt[now] < need)
        {
            pq.emplace(i);
        }
        while(!pq.empty())
        {
            auto p = pq.top();
            ll now = p%x;
            ll need = p/x+1;
            if(cnt[now] >= need) pq.pop();
            else break;
        }
        if(pq.empty())
        {
            cout << i+1 << endl;
        }
        else
        {
            auto p = pq.top();
            cout << p << endl;
        }
    }
}

