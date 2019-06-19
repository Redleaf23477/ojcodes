//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define l first
#define r second

const int N = 5001;

int n, q, tot;
int mutual[N][N];
int only[N];
int sign[N];
int sum[N];
int tmp[N];
P arr[N];

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
    cin >> n >> q;
    for(int i = 0; i < q; i++) 
    {
        cin >> arr[i].l >> arr[i].r;
        tmp[arr[i].l]++, tmp[arr[i].r+1]--;
    }
    for(int i = 1; i <= n; i++) 
    {
        sum[i] = sum[i-1]+tmp[i];
        tot += (sum[i] > 0);
        sign[i] = -1;
    }
    for(int i = 0; i < q; i++)
    {
        for(int p = arr[i].l; p <= arr[i].r; p++)
        {
            if(sum[p] == 1) only[i]++;
            if(sum[p] == 2)
            {
                if(sign[p] == -1) sign[p] = i;
                else
                {
                    mutual[i][sign[p]]++;
                    mutual[sign[p]][i]++;
                }
            }
        }
    }
}

void process()
{
    ll ans = 0;
    for(int i = 0; i < q; i++)
    {
        for(int j = 0; j < q; j++)
        {
            if(i == j) continue;
            ans = max(ans, tot-only[i]-only[j]-mutual[i][j]);
        }
    }
    cout << ans << endl;
}

