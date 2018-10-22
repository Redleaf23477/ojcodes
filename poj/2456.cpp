//
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 100005;

int n, c;
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
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
}

bool ok(int len)
{
    int left = c-1;
    int prvPos = arr[0], dist = len;
    for(int i = 1; i < n; i++)
    {
        dist -= (arr[i]-prvPos);
        if(dist <= 0) left--, dist = len;
        prvPos = arr[i];
    }
    return left <= 0;
}

void process()
{
    int high = 1000000009, low = 0, ans = -1, mid;
    while(low <= high)
    {
        mid = low+(high-low)/2;
        if(ok(mid)) ans = mid, low = mid+1;
        else high = mid-1;
    }
    printf("%d\n", ans);
}

