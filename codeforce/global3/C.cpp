//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
vector<int> arr, pos;

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
    arr.resize(n+1), pos.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
}

void process()
{
    vector<pair<int,int>> ans;
    for(int i = 1; i <= n/2; i++)
    {
        if(pos[i] == i) continue;
        if(abs(pos[i]-i) >= n/2)
        {
            ans.emplace_back(pos[i], i);
            pos[arr[i]] = pos[i];
            arr[pos[i]] = arr[i];
            arr[i] = i;
            pos[i] = i;
        }
        else if(pos[i] <= n/2)
        {
            ans.emplace_back(pos[i], n);
            ans.emplace_back(n, i);
            ans.emplace_back(pos[i], n);
            pos[arr[i]] = pos[i];
            arr[pos[i]] = arr[i];
            arr[i] = i;
            pos[i] = i;

        }
        else
        {
            ans.emplace_back(pos[i], 1);
            ans.emplace_back(1, n);
            ans.emplace_back(i, n);
            ans.emplace_back(pos[i], 1);
            int x = arr[i];
            int y = arr[n];
            arr[pos[i]] = y;
            arr[n] = x;
            pos[x] = n;
            pos[y] = pos[i];
            arr[i] = i;
            pos[i] = i;
        }
    }
    for(int i = n/2+1; i <= n; i++)
    {
        if(pos[i] == i) continue;
        ans.emplace_back(pos[i], 1);
        ans.emplace_back(1, i);
        ans.emplace_back(pos[i], 1);
        pos[arr[i]] = pos[i];
        arr[pos[i]] = arr[i];
        arr[i] = i;
        pos[i] = i;
    }

    cout << ans.size() << endl;
    for(auto a:ans) cout << a.first << " " << a.second << endl;
}

