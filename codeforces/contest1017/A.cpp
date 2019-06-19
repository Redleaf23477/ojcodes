//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
#define sum first
#define id second

bool cmp(const P &a, const P &b)
{
    if(a.sum != b.sum) return a.sum > b.sum;
    return a.id < b.id;
}

const int N = 1010;
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
    for(int i = 0; i < n; i++)
    {
        ll tot = 0;
        for(int j = 0; j < 4; j++) 
        {
            int x; cin >> x; tot += x;
        }
        arr[i].sum = tot;
        arr[i].id = i+1;
    }
    sort(arr, arr+n, cmp);
}

void process()
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i].id == 1)
        {
            cout << i+1 << endl; return;
        }
    }
}

