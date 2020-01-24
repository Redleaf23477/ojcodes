//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll arr[3];
ll n;

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
    for(int i = 0; i < 3; i++) cin >> arr[i];
    cin >> n;
    sort(arr, arr+3);
}

void process()
{
    n -= arr[2]-arr[0];
    n -= arr[2]-arr[1];
    if(n >= 0 && n%3 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

