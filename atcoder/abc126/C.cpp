//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n, k;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> k;
}

void process()
{
    double res = 0;
    if(n >= k)
    {
        res += (n-k+1)/(double)n;
    }
    int pw = 1;
    while(pw < k) pw *= 2;
    for(int i = 1; i <= n && i < k; i++)
    {
        while(pw * i / 2 >= k) pw /= 2;
        res += 1.0/pw/n;
    }
    cout << fixed << setprecision(10) << res << endl;

}

