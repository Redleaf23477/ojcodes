//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

int n;
ll arr[2*N];

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
    cin >> n; n*=2;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
}

void process()
{
    ll mn = (arr[n/2-1]-arr[0])*(arr[n-1]-arr[n/2]);
    for(int i = 1; i < n/2; i++)
    {
        mn = min(mn, (arr[i+n/2-1]-arr[i])*(arr[n-1]-arr[0]));
    }
    cout << mn << endl;
}

