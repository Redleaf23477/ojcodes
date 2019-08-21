//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1000006;

ll n, m, k;
ll arr[N], cnt[N], rep[N];

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
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void report(int l, int r) { rep[l]++, rep[r+1]--; }

void process()
{
    for(int l = 0, r = 0; r < n; r++)
    {
        ++cnt[arr[r]];
        while(cnt[arr[r]] > 1)
        {
            --cnt[arr[l]];
            l++;
        }
        if(r-l+1 >= k) report(l, r);
    }
    vector<int> ans;
    for(int i = 0, sum = 0; i < n; i++)
    {
        sum += rep[i];
        if(sum > 0) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for(size_t i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i+1 == ans.size()];
}

