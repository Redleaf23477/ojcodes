//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<int> arr;

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
    arr.resize(2*n);
    for(int i = 0; i < 2*n; i++) cin >> arr[i];
}

void process()
{
    map<int, int> mp; // mp[delta = one - two] = min eat
    int one = 0, two = 0;
    mp[0] = n;
    for(int i = 2*n-1; i >= n; i--)
    {
        if(arr[i] == 1) one++;
        else two++;
        int delta = one-two;
        if(mp.count(delta) == 0) mp[delta] = i - n;
        mp[delta] = i-n;
    }
    int ans = min(mp[0]+n, 2*n);
    one = 0; two = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1) one++;
        else two++;
        int delta = one-two;
        if(mp.count(-delta) != 0) ans = min(ans, n-i-1 + mp[-delta]);
    }
    cout << ans << endl;
}

