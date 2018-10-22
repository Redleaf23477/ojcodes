//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;

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
    cin >> n;
}

void process()
{
    ll sum = 0;
    stack<pair<int, int>> stk;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        int same = 1;
        while(!stk.empty() && stk.top().first <= x)
        {
            sum += stk.top().second;
            if(x == stk.top().first) same += stk.top().second;
            stk.pop();
        }
        if(!stk.empty()) sum++;
        stk.push(make_pair(x, same));
    }
    cout << sum << endl;
}

