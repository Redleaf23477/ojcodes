//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define val first
#define idx second

const int N = 200005;
int n, m, d;
P arr[N];
int ans[N];

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
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
        arr[i].idx = i;
    }
    sort(arr, arr+n);
}

void process()
{
    map<int, int> mp;
    int day = 1;
    ans[arr[0].idx] = 1;
    mp[arr[0].val] = 1;
    for(int i = 1; i < n; i++)
    {
        auto it = mp.upper_bound(arr[i].val-d-1);
        if(it == mp.begin())
        {
            mp[arr[i].val] = ++day;
            ans[arr[i].idx] = day;
        }
        else
        {
            it--;
            mp[arr[i].val] = it->second;
            ans[arr[i].idx] = it->second;
            mp.erase(it);
        }
    }
    cout << day << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

