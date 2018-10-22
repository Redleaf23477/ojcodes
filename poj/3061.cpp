// 爬行法
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 100005;

ll n, s;
ll arr[N];

void init();
void process();

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    scanf("%lld %lld", &n, &s);
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
}

void process()
{
    ll sum = 0, l = 0, r = 0, ans = N;
    for(r = 0; r < n; r++)
    {
        sum += arr[r];
        while(sum >= s) ans = min(ans, r-l+1), sum -= arr[l++];
    }
    printf("%lld\n", (ans == N? 0:ans));
}

