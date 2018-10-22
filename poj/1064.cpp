//
#include <cstdio>

using namespace std;
typedef long long int ll;

const int N = 10004;

ll n, k;
ll arr[N];

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
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++)
    {
        ll a, b; scanf("%lld.%lld", &a, &b);
        arr[i] = a*100+b;
    }
}

bool ok(ll len)
{
    ll cnt = 0;
    for(int i = 0; i < n; i++) cnt += arr[i]/len;
    return cnt >= k;
}

void process()
{
    ll high = 10000006, low = 1, mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, low = mid+1;
        else high = mid-1;
    }
    if(ans == -1) printf("0.00\n");
    else printf("%lld.%02lld\n", ans/100, ans%100);
}

