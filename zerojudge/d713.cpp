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
    priority_queue<ll, vector<ll>, greater<ll>> gpq;
    priority_queue<ll, vector<ll>, less<ll>> lpq;
    // less mid greater
    ll x;
    while(cin >> x)
    {
        if(lpq.empty() || x > lpq.top()) gpq.push(x);
        else lpq.push(x);
        if(gpq.size() > lpq.size()) lpq.push(gpq.top()), gpq.pop();
        if(lpq.size() > gpq.size()) gpq.push(lpq.top()), lpq.pop();
        if(gpq.size() == lpq.size()) cout << (gpq.top()+lpq.top())/2 << endl;
        else if(gpq.size() > lpq.size()) cout << gpq.top() << endl;
        else cout << lpq.top() << endl;
    }
}

