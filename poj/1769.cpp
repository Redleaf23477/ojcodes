//
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define l first
#define r second

const int N = 50004, M = 500005;
const int INF = (1<<30);
int n, m;
int st[4*N];
P sorter[M];

void build_st(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx] = INF; return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    build_st(l, mid, lson);
    build_st(mid+1, r, rson);
    st[idx] = min(st[lson], st[rson]);
}

void modify(int l, int r, int idx, int pos, int val)
{
    if(pos < l || r < pos) return;
    if(l == pos && r == pos)
    {
        st[idx] = min(st[idx], val);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    modify(l, mid, lson, pos, val);
    modify(mid+1, r, rson, pos, val);
    st[idx] = min(st[lson], st[rson]);
}

int query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return INF;
    if(L <= l && r <= R) return st[idx];
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    return min( query(l, mid, lson, L, R), query(mid+1, r, rson, L, R) );
}

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &sorter[i].l, &sorter[i].r);
    }
    build_st(0, n, 1);
}

void process()
{
    for(int i = 0; i < m; i++)
    {
        if(sorter[i].l == 1) modify(0, n, 1, sorter[i].r, 1);
        else
        {
            int q = query(0, n, 1, sorter[i].l, sorter[i].r);
            if(q == INF) continue;
            else modify(0, n, 1, sorter[i].r, q+1);
        }
    }
    printf("%d\n", query(0, n, 1, n, n));
}

