//
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

class Bit
{
private:
    static const int N = 100005;
    int n;
    ll bit[N];
    inline int lowbit(int x) { return x&(-x); }
public:
    void init(int len)
    {
        n = len;
        for(int i = 0; i <= n; i++) bit[i] = 0;
    }
    void add(int pos, ll val)
    {
        for(; pos <= n; pos += lowbit(pos))
            bit[pos] += val;
    }
    ll query(int pos)
    {
        ll sum = 0;
        for(; pos; pos -= lowbit(pos))
            sum += bit[pos];
        return sum;
    }
};

const int N = 100005;
int n, q;
Bit sum, tag;

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
    scanf("%d %d", &n, &q);
    sum.init(n), tag.init(n);
    for(int i = 1; i <= n; i++)
    {
        ll v; scanf("%lld", &v);
        sum.add(i, v);
    }
}

void process()
{
    char cmd;
    ll l, r, v;
    while(q--)
    {
        scanf(" %c", &cmd);
        if(cmd == 'Q')
        {
            ll ans = 0;
            scanf("%lld %lld", &l, &r);
            ans += sum.query(r) - sum.query(l-1);
            ans += tag.query(r)*r - tag.query(l-1)*(l-1);
            printf("%lld\n", ans);
        }
        else
        {
            scanf("%lld %lld %lld", &l, &r, &v);
            sum.add(r+1, v*r);
            sum.add(l, -v*(l-1));
            tag.add(l, v);
            tag.add(r+1, -v);
        }
    }
}

