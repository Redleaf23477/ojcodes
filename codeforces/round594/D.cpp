//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
string str;

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
    cin >> n >> str;
}

ll test(string &str)
{
    // 1-st phase : if valid
    int flg = 0; int mn = n, mnidx = -1;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '(') flg++;
        else flg--;
        if(flg < mn) mn = flg, mnidx = i;
    }
    if(flg != 0) return 0;
    // 2-nd phase : how many
    int res = (mnidx == -1? 0 : 1);
    flg = 0;
    for(int i = mnidx+1; i < n; i++)
    {
        if(str[i] == '(') flg++;
        else flg--;
        if(flg == 0) res++;
    }
    return res;
}

void process()
{
    // ans = max beauty, swap(x, y)
    ll ans = 0, x = 0, y = 0;
    string tmp = str;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            swap(tmp[i], tmp[j]);
            ll res = test(tmp);
            if(res > ans) ans = res, x = i, y = j;
            swap(tmp[i], tmp[j]);
        }
    cout << ans << endl;
    cout << x+1 << " " << y+1 << endl;
}

