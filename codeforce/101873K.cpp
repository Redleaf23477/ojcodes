//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
using P = pair<ll, string> ;

const int N = 100005;
ll n, d, k;
P arr[N];

bool cmp(const P &a, const P &b)
{
    return a.first > b.first;
}

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
    cin >> n >> d >> k;
    for(int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+n, cmp);
}

void process()
{
    ll tot = 0;
    for(int i = 0; i < k; i++) tot += arr[i].first;
    if(tot >= d)
    {
        cout << k << endl;
        for(int i = 0; i < k; i++) cout << arr[i].second << ", YOU ARE FIRED!" << endl;
    }
    else cout << "impossible" << endl;
}

