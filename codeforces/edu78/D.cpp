//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

#define lowbit(x) x&-x
const int N = 2*500005;

int n;
int bit[N];

int sum(int x)
{
    int rtn = 0;
    for(;x;x-=lowbit(x)) rtn += bit[x];
    return rtn;
}

void modify(int x, int d)
{
    for(;x<=n;x+=lowbit(x)) bit[x] += d;
}

struct Seg 
{
    int l, r, good;
    Seg(int l = 0, int r = 0) : l(l), r(r), good(false) {}
};

bool operator < (const Seg &lhs, const Seg &rhs)
{
    return lhs.l < rhs.l || (lhs.l == rhs.l && lhs.r < rhs.r);
}

int vn;
vector<Seg> arr;

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
    cin >> vn;
    n = 2*vn;
    arr.resize(vn);
    for(int i = 0; i < vn; i++) cin >> arr[i].l >> arr[i].r;
}

int run()
{
    sort(arr.begin(), arr.end());
    memset(bit, 0, sizeof(bit));
    for(int i = 0; i < vn; i++) modify(arr[i].r, 1);
    int en = 0;
    for(int i = 0; i < vn; i++)
    {
        cerr << "i = " << i << endl;
        modify(arr[i].r, -1);
        // add en
        int add = 0;
        int tooRight = arr.end() - upper_bound(arr.begin() + i, arr.end(), Seg(arr[i].r, arr[i].r));
        cerr << "tooRight = " << tooRight << endl;
        assert(tooRight >= 0);
        add += sum(2*vn) - sum(arr[i].r);
        cerr << "sum = " << add << endl;
        add -= tooRight;
        cerr << "add = " << add << endl;
        assert(add >= 0);
        if(add > 0) arr[i].good = true;
        en += add;
    }
    return en;
}

bool notCC()
{
    vector<int> l(2*vn+2, 0), r(2*vn+2, 0);
    for(int i = 0; i < vn; i++) l[arr[i].l]++, r[arr[i].r]++;
    int flg = 0, s = 0;
    for(int i = 1; i < 2*vn+2; i++)
    {
        if(l[i] > 0) 
        {
            if(s == 0) flg++;
            s += l[i];
        }
        if(r[i] > 0)
        {
            s -= r[i];
        }
    }
    return flg > 1;
}

void process()
{
    if(notCC()) { cout << "NO" << endl; return; }
    int en = run();
    for(int i = 0; i < vn; i++) 
    {
        swap(arr[i].l, arr[i].r);
        arr[i].l = n - arr[i].l + 1, arr[i].r = n - arr[i].r + 1;
    }
    run();
    bool cc = true;
//    cerr << "en = " << en << endl;
    for(int i = 0; i < vn; i++) cc = cc && arr[i].good;
    if(vn == 1) cout << "YES" << endl;
    else if(cc && en == vn-1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

