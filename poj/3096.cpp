// poj 3096 saruman's army
// greedy
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 1010;

int r, n;
int arr[N];

void init();
void process();

int main()
{
    while(~scanf("%d %d", &r, &n) && n > 0)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
}

void process()
{
    int cnt = 0;
    int rbd = arr[0]+r;
    while(true)
    {
        cnt++;
        int *ptr = upper_bound(arr, arr+n, rbd);
        if(ptr == arr+n) break;
        rbd = *(ptr-1)+r;
        ptr = upper_bound(arr, arr+n, rbd);
        if(ptr == arr+n) break;
        rbd = *ptr+r;
    }
    printf("%d\n", cnt);
}

