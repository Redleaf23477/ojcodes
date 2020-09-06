// Tomioka has no friends
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

const int INF = 1e9+7;

ll solve(int l, int r, vector<int> &arr, int sub)
{
    cerr << "l = " << l << ", r = " << r << endl;
    int mn = INF;
    for(int i = l; i <= r; i++) mn = min(mn, arr[i]-sub);
    int mn_cnt = 0;
    for(int i = l; i <= r; i++) if(arr[i]-sub == mn) mn_cnt++;
    if(mn_cnt >= mn)
    {
        int ans = mn_cnt-1;
        int ll = -1;
        for(int i = l; i <= r; i++)
        {
            if(arr[i]-sub == mn)
            {
                if(ll != -1) 
                {
                    ans += solve(ll, i-1, arr, sub+mn);
                    ll = -1;
                }
            }
            else if(ll == -1) ll = i;
        }
        if(ll != -1) ans += solve(ll, r, arr, sub+mn);
        return ans;
    }
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n); for(auto &x:arr) cin >> x;
    cout << n - solve(0, n-1, arr, 0) << endl;
    cout.flush();
    return 0;
}

