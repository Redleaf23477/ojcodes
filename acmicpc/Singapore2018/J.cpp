//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
int arr[1000];

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
}

void process()
{
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr[x]++, arr[y+1]--;
    }
    int cnt = 0, acc = 0;
    for(int i = 1; i <= 365; i++)
    {
        acc += arr[i];
        if(acc > 0) cnt++;
    }
    cout << cnt << endl;
}

