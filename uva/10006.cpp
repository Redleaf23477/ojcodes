// UVa 10006
// prime test, fast pow
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 65003;
bool isprime[N];

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
    fill(isprime, isprime+N, true);
    int sqrtn = sqrt(N)+1;
    for(int i = 2; i < sqrtn; i++)
    {
        if(isprime[i])
        {
            for(int j = i*i; j < N; j+=i) isprime[j] = false;
        }
    }
}

ll fpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    if(n%2 == 0) return fpow(a*a%m, n/2, m);
    else return a*fpow(a*a%m, n/2, m)%m;
}

void process()
{
    int x;
    while(cin >> x && x)
    {
        bool normal = isprime[x];
        for(int i = 2; i < x && !normal; i++)
        {
            if(fpow(i, x, x) != i) normal = true;
        }
        if(normal) cout << x << " is normal." << endl;
        else cout << "The number " << x << " is a Carmichael number." << endl;
    }
}

