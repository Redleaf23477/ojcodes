//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 500005;
const ll INF = (1ll<<60);
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
}

bool allPos()
{
    for(int i = 0; i < n; i++)
        if(arr[i] < 0) return false;
    return true;
}

bool allNeg()
{
    for(int i = 0; i < n; i++)
        if(arr[i] > 0) return false;
    return true;
}

void process()
{
    // case 0: size == 1
    if(n == 1)
    {
        cout << arr[0] << endl;
    }
    // case 1: all positive
    else if(allPos())
    {
        ll mn = INF, sum = 0;
        for(int i = 0; i < n; i++)
            mn = min(mn, arr[i]), sum += arr[i];
        sum -= 2*mn;
        cout << sum << endl;
    }
    // case 2: all negative
    else if(allNeg())
    {
        ll mn = INF, sum = 0;
        for(int i = 0; i < n; i++)
            arr[i] = -arr[i], mn = min(mn, arr[i]), sum += arr[i];
        sum -= 2*mn;
        cout << sum << endl;
    }
    // case 3
    else
    {
        ll sum = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] < 0) sum -= arr[i];
            else sum += arr[i];
        cout << sum << endl;
    }
}

