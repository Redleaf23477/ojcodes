//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define x first
#define y second

int n;
vector<P> arr;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.clear();
    for(int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        arr.emplace_back(x, y);
    }
}

void process()
{
    set<P> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if((arr[i].x >= arr[j].x && arr[i].y >= arr[j].y)||(arr[j].x >= arr[i].x && arr[j].y >= arr[i].y)) continue;
            P tmp(arr[i].x-arr[j].x, arr[i].y-arr[j].y);
            ll g = __gcd(tmp.x, tmp.y);
            tmp.x /= g, tmp.y /= g;
            s.insert(tmp);
        }
    }
//    for(auto x: s) cout << x.x << " " << x.y << endl;
    cout << s.size()+1 << endl;
}

