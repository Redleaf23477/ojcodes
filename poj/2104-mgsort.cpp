// k-th number using merge sort tree
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 100005;
int n, q;
int arr[N];
vector<int> st[4*N];
vector<int> &sorted = st[1];

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void build(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx].push_back(arr[l]);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    st[idx].resize(st[lson].size()+st[rson].size());
    merge(st[lson].begin(), st[lson].end(), st[rson].begin(), st[rson].end(), st[idx].begin());
}

void init()
{
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    build(0, n-1, 1);
}

int getRank(int l, int r, int idx, int L, int R, int x)
{
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) 
    {
        return upper_bound(st[idx].begin(), st[idx].end(), x) - st[idx].begin();
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    return getRank(l, mid, lson, L, R, x) + getRank(mid+1, r, rson, L, R, x);
}

void process()
{
    int l, r, k;
    while(q--)
    {
        scanf("%d %d %d", &l, &r, &k);
        l--, r--;
        int high = n-1, low = 0, mid, ans = -1;
        while(low <= high)
        {
            mid = (high+low)/2;
            int rk = getRank(0, n-1, 1, l, r, sorted[mid]);
            if(rk > k) high = mid-1;
            else if(rk == k) ans = sorted[mid], high = mid-1;
            else low = mid+1;
        }
        printf("%d\n", ans);
    }
}

