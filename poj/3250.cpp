//
#include <cstdio>
#include <stack>

using namespace std;
typedef long long ll;

const int N = 80004;

int n;
int arr[N], in[N];

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
    ll ans = 0;
    stack<pair<int, int> > stk;
    for(int i = 0; i < n; i++)
    {
        while(stk.size() && arr[i] >= stk.top().second)
        {
            int idx = stk.top().first, h = stk.top().second; stk.pop();
//            printf("..%d => %d\n", idx, i-idx-1);
            ans += i-idx-1;
        }
        stk.push(make_pair(i, arr[i]));
    }
    while(stk.size())
    {
        int idx = stk.top().first; stk.pop();
        ans += n-idx-1;
    }
    printf("%lld\n", ans);
}

