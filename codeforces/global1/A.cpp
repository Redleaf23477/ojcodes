//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

ll b, k;
ll arr[N];

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
    cin >> b >> k;
    for(int i = 0; i < k; i++) cin >> arr[i];
}

void process()
{
    bool even = (arr[k-1]%2 == 0);
    for(int pw = 1, i = k-2; pw < k; pw++, i--)
    {
        bool tmp = (arr[i]%2 == 0) || (b%2 == 0);
        if(tmp == false) even ^= 1;
    }
    if(even) cout << "even" << endl;
    else cout << "odd" << endl;
}

