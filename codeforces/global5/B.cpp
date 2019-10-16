//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
#define in first
#define out second

const int N = 100005;

int n;
vector<P> arr;
int bit[N];

#define lowbit(x) (x)&(-x)

int query(int x)
{
    int rtn = 0;
    for(;x;x-=lowbit(x)) rtn += bit[x];
    return rtn;
}

void modify(int x, int d)
{
    for(;x<=n;x+=lowbit(x)) bit[x] += d;
}


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
    arr.resize(n);
    for(int i = 1; i <= n; i++) 
    {
        int id; cin >> id; id--;
        arr[id].in = i;
    }
    for(int i = 1; i <= n; i++) 
    {
        int id; cin >> id; id--;
        arr[id].out = i;
    }
    sort(arr.begin(), arr.end());

}

void process()
{
    int fine = 0;
    for(auto p : arr)
    {
        if(query(n) - query(p.second) > 0) fine++;
        modify(p.second, 1);
    }
    cout << fine << endl;
}

