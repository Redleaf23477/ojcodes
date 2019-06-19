//  
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005, M = 15000001;

bool notPrime[M];
vector<int> primes;

int n;
int arr[N];

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
    for(ll i = 2; i < M; i++)
        if(!notPrime[i])
        {
            primes.push_back(i);
            for(ll j = i*i; j < M; j+=i) notPrime[j] = true;
        }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int fullGCD = arr[0];
    for(int i = 1; i < n; i++) fullGCD = __gcd(fullGCD, arr[i]);
    for(int i = 0; i < n; i++) arr[i] /= fullGCD;
}

void process()
{
    int ans = n-1;
    bool all_1 = true;
    for(int i = 0; i < n; i++) all_1 = all_1 && (arr[i] == 1);
    for(auto p:primes)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += (arr[i]%p != 0);
        ans = min(ans, cnt);
    }
    if(all_1) ans = -1;
    cout << ans << endl;
}

