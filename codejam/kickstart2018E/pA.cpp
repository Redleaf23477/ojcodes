//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 5050;

int n, k;
ll arr[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
}

void process()
{
    int belly = k, day = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= day) continue;
        belly--, cnt++;
        if(belly == 0) belly = k, day++;
    }
    cout << cnt << endl;
}

