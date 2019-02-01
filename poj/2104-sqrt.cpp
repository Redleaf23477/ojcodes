// k-th number using square root decomposition
// tle
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 100005;
int n, q, boxSize, boxNum;
int arr[N];
int sorted[N];
int box[N];

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
    boxSize = 1000;
    boxNum = n/boxSize + (n%boxSize != 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sorted[i] = box[i] = arr[i];
    }
    sort(sorted, sorted+n);
    for(int i = 0; i < boxNum; i++)
    {
        sort(box+i*boxSize, box+min((i+1)*boxSize, n));
    }
}

int getRank(int l, int r, int x)
{
    int rk = 0;
    // left and right not complete box
    while(l <= r && l%boxSize != 0) rk += (arr[l++] <= x);
    while(l <= r && r%boxSize != boxSize-1) rk += (arr[r--] <= x);
    // complete box
    while(l <= r)
    {
        rk += upper_bound(box+l, box+l+boxSize, x) - (box+l);
        l += boxSize;
    }
    return rk;
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
            int rk = getRank(l, r, sorted[mid]);
            if(rk > k) high = mid-1;
            else if(rk == k) ans = sorted[mid], high = mid-1;
            else low = mid+1;
        }
        printf("%d\n", ans);
    }
}

