//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
int n, k, a, b;
int pos[N];

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
    cin >> n >> k >> a >> b;
    for(int i = 0; i < k; i++) cin >> pos[i];
    sort(pos, pos+k);
}

ll cntAvNum(int l, int r)
{
    int *lpos = lower_bound(pos, pos+k, l)-1;
    int *rpos = upper_bound(pos, pos+k, r)-1;
//    cout << "(" << l << "," << r << ") = " << rpos-lpos << endl;
    return rpos-lpos;
}

ll f(int l, int r)  // segment of [l, r]
{
    ll avNum = cntAvNum(l, r);
    if(avNum == 0) return a;
    // case1: kill all
    ll case1 = b*avNum*(r - l + 1);
    if(l == r) return case1;
    // case2: dc
    ll mid = (l+r)/2;
    ll case2 = f(l, mid) + f(mid+1, r);
    return min(case1, case2);
}

void process()
{
    cout << f(1, 1<<n) << endl;
}

