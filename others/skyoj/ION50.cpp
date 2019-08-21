//

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int n;
vector<int> stk;

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
}

void process()
{
    string cmd;
    while(n--)
    {
        cin >> cmd;
        if(cmd == "clear")
        {
            ll x; cin >> x;
            stk.emplace_back(x);
        }
        else if(cmd == "break") stk.pop_back();
        else
        {
            ll x; cin >> x;
            if(x > stk.size()) cout << "FAT" << endl;
            else cout << stk[x-1] << endl;
        }
    }
}

