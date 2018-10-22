//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000001;
int n;
ll avg;
ll arr[N];
ll c[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    avg = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= n;
    for(int i = 0; i < n-1; i++) c[i] = avg-arr[i];
    c[n-1] = 0;
    for(int i = n-2; i >= 0; i--) c[i] += c[i+1];
    for(int i = 0; i < n; i++) c[i] = -c[i];
    sort(c, c+n);
    ll mid = c[(n+1)/2], sum = 0;
    for(int i = 0; i < n; i++) sum += abs(mid-c[i]);
    cout << sum << endl;
}

void process()
{
}

