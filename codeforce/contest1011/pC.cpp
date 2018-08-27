//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, m;
vector<int> arr;

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
    vector<int> a(n), b(n); arr.resize(2*n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) arr[i*2-1] = b[i], arr[i*2] = a[i];
    arr[0] = a[0], arr[2*n-1] = b[0];
}

void process()
{
    double tot = m;
    bool invalid = false;
    for(int i = 2*n-1; i >= 0; i--)
    {
        if(arr[i] == 1) { invalid = true; break; }
        double fuel = tot/(arr[i]-1);
        tot += fuel;
    }
    cout << fixed << setprecision(7) << (invalid? -1:tot-m) << endl;
}

