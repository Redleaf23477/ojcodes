//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 102, K = 100005;

int n, k;
ll arr[N];
bool dp[K];  // dp[i] = true : First hand will win if there are i stones initially

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
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin  >> arr[i];
}

void process()
{
    dp[0] = false;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= arr[j])
            {
                dp[i] |= !dp[i-arr[j]];
            }
        }
    }
    if(dp[k] == true) cout << "First" << endl;
    else cout << "Second" << endl;
}

