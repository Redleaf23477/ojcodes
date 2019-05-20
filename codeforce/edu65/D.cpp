//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
string str;

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
    cin >> n;
    cin >> str;
}

void process()
{
    stack<bool> stk;
    string ans = str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '(')
        {
            if(stk.empty() || stk.top() == 1) ans[i] = '0', stk.push(0);
            else ans[i] = '1', stk.push(1);
        }
        else
        {
            ans[i] = (stk.top()? '1' : '0');
            stk.pop();
        }
    }
    cout << ans << endl;
}

