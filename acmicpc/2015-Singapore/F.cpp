//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define l first
#define r second

const int N = 102;
int n;
P arr[N];

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
    for(int i = 0; i < n; i++) cin >> arr[i].l >> arr[i].r;
    sort(arr, arr+n);
}

void process()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].l == -1) continue;
        int bestT = arr[i].l, mxLeft = arr[i].l;
        for(int t = arr[i].l; t <= arr[i].r; t++)
        {
            int tmpl = 3*N;
            for(int j = i+1; j < n; j++)
            {
                if(t < arr[j].l) tmpl = min(tmpl, arr[j].l);
                if(t > arr[j].r) tmpl = min(tmpl, arr[j].l);
            }
            if(tmpl > mxLeft) bestT = t, mxLeft = tmpl;
        }
        for(int j = i; j < n; j++)
        {
            if(bestT < arr[j].l) break;
            if(bestT <= arr[j].r) arr[j].l = -1;
        }
        ans++;
    }
    cout << ans << endl;
}

