// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;
using Pt = pair<ll,ll>;
#define x first
#define y second

int n;
vector<Pt> arr;

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
    cin >> n;
    arr.resize(n);
    for(auto &pt : arr)
        cin >> pt.x >> pt.y;
}

void process()
{
    if(n%2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    bool good = true;
    for(int i = 0; i < n/2; i++)
    {
        Pt a = arr[i], b = arr[i+1];
        Pt c = arr[i+n/2], d = arr[(i+n/2+1)%n];
        ll dx = b.x-a.x, dy = b.y-a.y;
        Pt d2(c.x-dx, c.y-dy);
        if(d2 == d) continue;
        else { good = false; break; }
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

