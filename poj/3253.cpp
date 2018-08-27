// poj 3253 fence repair
// greedy
#include <cstdio>
#include <queue>

using namespace std;
typedef long long int ll;

const int N = 20020;

int n;
int arr[N];

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
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void process()
{
    ll tot = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 0; i < n; i++) pq.push(arr[i]);
    while(pq.size() > 1)
    {
        ll sum = pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        tot += sum;
        pq.push(sum);
    }
    printf("%lld\n", tot);
}

