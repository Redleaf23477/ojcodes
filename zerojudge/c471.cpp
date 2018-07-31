#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
#define w first
#define f second

const int N = 100005;
int n;
P obj[N];
ll post[N];
void init();
void process();

bool cmp(P a, P b)
{
    return a.w*b.f < a.f*b.w;
}

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
    for(int i = 0; i < n; i++) cin >> obj[i].w;
    for(int i = 0; i < n; i++) cin >> obj[i].f;
    sort(obj, obj+n, cmp);
    post[n-1] = 0;
    for(int i = n-2; i >= 0; i--) post[i] = obj[i+1].f+post[i+1];
}

void process()
{
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += obj[i].w*post[i];
    cout << sum << endl;
}

