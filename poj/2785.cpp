//
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 4040;

int n;
ll arr[N][4];

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
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
            scanf("%lld", &arr[i][j]);
    }
}

void process()
{
    ll cnt = 0;
    vector<int> left(n*n), right(n*n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            left[i*n+j] = arr[i][0]+arr[j][1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            right[i*n+j] = arr[i][2]+arr[j][3];
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for(int i = 0; i < left.size(); i++)
        cnt += upper_bound(right.begin(), right.end(), -left[i])-lower_bound(right.begin(), right.end(), -left[i]);
    printf("%lld\n", cnt);
}

