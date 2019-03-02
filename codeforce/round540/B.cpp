//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 200005;
int n;
ll odd[N], even[N];
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
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(i%2 == 0) even[i] += even[i-1]+arr[i], odd[i] = odd[i-1];
        else odd[i] += odd[i-1]+arr[i], even[i] = even[i-1];
    }
//    for(int i = 1; i <= n; i++) cout << odd[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= n; i++) cout << even[i] << " ";
//    cout << endl;
}

void process()
{
    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        //if(i%2 == 1)
        {
            ll e = even[i-1] + (odd[n]-odd[i]);
            ll o = odd[i-1] + (even[n]-even[i]);
            if(e == o) cnt++;
//            cout << i << " " << e << " " << o << endl;
        }
    }
    cout << cnt << endl;
}

