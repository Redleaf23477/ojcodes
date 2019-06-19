//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;
int n;
ll arr[N];

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
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
}

void process()
{
    ll sum = 0;
    for(int i = 0, j = n-1; i < j; i++, j--)
    {
        sum += (arr[i]+arr[j])*(arr[i]+arr[j]);
    }
    cout << sum << endl;
}

