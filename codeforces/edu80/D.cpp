//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005, M = 10;

ll n, m;
ll arr[N][M];

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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
}

pair<int,int> test(ll small)
{
    vector<int> msk(1<<m, -1);
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        for(int j = 0; j < m; j++)
        {
            tmp |= ((arr[i][j] >= small)<<j);
        }
        msk[tmp] = i;
    }
    for(int i = 0; i < (1<<m); i++)
    {
        if(msk[i] == -1) continue;
        for(int j = 0; j < (1<<m); j++)
        {
            if(msk[j] == -1) continue;
            if((i | j) == (1<<m)-1)
                return make_pair(msk[i], msk[j]);
        }
    }
    return make_pair(-1, -1);
}

void process()
{
    ll low = 0, high = 1e9, mid;
    pair<int,int> ans(-1, -1);
    while(low <= high)
    {
        mid = (low+high)/2;
        auto res = test(mid);
        if(res.first == -1 && res.second == -1) high = mid-1;
        else low = mid+1, ans = res;
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;
}

