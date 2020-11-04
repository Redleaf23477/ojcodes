// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    init();
    while(T--)
    {
        process();
    }
    cout.flush();
    return 0;
}

vector<int> sp;

void init()
{
    sp.resize(1000006);
    iota(sp.begin(), sp.end(), 0);
    for(int i = 2; i*i < 1000006; i++)
    {
        if(sp[i] != i) continue;
        for(int j = i*i; j < 1000006; j += i)
            if(sp[j] == j) sp[j] = i;
    }
}

void process()
{
    ll n, k; cin >> n >> k;
    cout << n+sp[n]+2*(k-1) << endl;
}
