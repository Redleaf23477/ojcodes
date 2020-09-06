// Tomioka has no friends
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string str; cin >> str;
        string ans(n, '0');
        for(int i = 0; i < n; i++)
        {
            ans[i] = str[2*i];
        }
        cout << ans << endl;
    }
    cout.flush();
    return 0;
}

