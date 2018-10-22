//
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int N = 1000006;
int n, totLesson;
int sum[N];
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
    vector<int> tmp(n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        tmp[i] = arr[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
    totLesson = tmp.size();
    for(int i = 0; i < n; i++) arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin();
}

void process()
{
    ll lessonNum = 0, ans = N;
    for(ll l = 0, r = 0; r < n; r++)
    {
        if(sum[arr[r]] == 0) lessonNum++;
        sum[arr[r]]++;
        while(lessonNum == totLesson)
        {
            ans = min(ans, r-l+1);
            if(sum[arr[l]] == 1) lessonNum--;
            sum[arr[l]]--;
            l++;
        }
    }
    printf("%lld\n", ans);
}

