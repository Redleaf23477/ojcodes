//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
ll phi[N], sum[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    // build phi
    for(int i = 0; i < N; i++) phi[i] = i;
    for(int i = 2; i < N; i++)
    {
        if(phi[i] == i) // is prime
        {
            for(int j = i; j < N; j += i)
                phi[j] = phi[j]*(i-1)/i;
        }
    }
    // build sum
    sum[0] = phi[0];
    for(int i = 1; i < N; i++) sum[i] = phi[i]+sum[i-1];
}

void process()
{
    int T; cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        cout << sum[b]-sum[a-1] << endl;
    }
}

