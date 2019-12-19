//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<int> arr, pos;

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
    arr.resize(n);
    pos.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        arr[i]--;
        pos[arr[i]] = i;
    }
}

void process()
{
    vector<int> ans(n, 0);
    ans[0] = 1;
    int l, r;
    l = pos[0], r = pos[0];
    for(int i = 1; i < n; i++)
    {
        if(l <= pos[i] && pos[i] <= r) ans[i] = (r-l+1 == i+1);
        else if(r != n-1 && arr[r+1] == i) r++, ans[i] = (r-l+1 == i+1);
        else if(l != 0 && arr[l-1] == i) l--, ans[i] = (r-l+1 == i+1);
        else
        {
            int p = pos[i];
            l = min(l, p), r = max(r, p);
        }
    }
    for(auto a : ans) cout << a;
    cout << endl;
}

