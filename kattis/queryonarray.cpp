// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using LL = long long int;
using I128 = __int128;

const I128 MOD = (I128)1e9+7;

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

int n, q;
vector<I128> arr; // prefix sum of array
vector<vector<I128>> sum; // prefix sum of power of x
vector<tuple<int,LL,LL>> storage;

void init()
{
    cin >> n >> q;
    arr.assign(n+1, 0);
    sum.assign(4, vector<I128>(n+1, 0));
    for(LL i = 1; i <= n; i++)
    {
        sum[3][i] = sum[3][i-1] + i*i*i;
        sum[2][i] = sum[2][i-1] + i*i;
        sum[1][i] = sum[1][i-1] + i;
        sum[0][i] = sum[0][i-1] + 1;
    }
}

LL query(LL l, LL r)
{
    I128 ans = arr[r] - arr[l-1];
    for(auto [sign, x, y] : storage)
    {
        LL L = max(x, l), R = min(y, r);
        if(L > R) continue;
        I128 tmp = 0;

        // i^3
        tmp += (sum[3][R] - sum[3][L-1]) * 1;
        // i^2
        tmp += (sum[2][R] - sum[2][L-1]) * (-3*x + 6);
        // i^1
        tmp += (sum[1][R] - sum[1][L-1]) * (3*x*x - 12*x + 11);
        // i^0
        tmp += (sum[0][R] - sum[0][L-1]) * (-x*x*x + 6*x*x - 11*x + 6);

        ans += sign * tmp;
    }
    return (LL)((ans % MOD + MOD) % MOD);
}

void flush()
{
    vector<vector<I128>> buff(4, vector<I128>(n+2, 0));
    for(auto [sign, x, y] : storage)
    {
        // i^3
        buff[3][x] += sign * 1;
        buff[3][y+1] -= sign * 1;
        // i^2
        buff[2][x] += sign * (-3*x + 6);
        buff[2][y+1] -= sign * (-3*x + 6);
        // i^1
        buff[1][x] += sign * (3*x*x - 12*x + 11);
        buff[1][y+1] -= sign * (3*x*x - 12*x + 11);
        // i^0
        buff[0][x] += sign * (-x*x*x + 6*x*x - 11*x + 6);
        buff[0][y+1] -= sign * (-x*x*x + 6*x*x - 11*x + 6);
    }
    for(int j = 0; j < 4; j++)
        for(int i = 1; i <= n; i++)
            buff[j][i] += buff[j][i-1];

    vector<I128> buff2(n+1, 0);
    for(int i = 1; i <= n; i++)
        for(LL j = 0, pw = 1; j < 4; j++, pw *= i)
            buff2[i] += pw * buff[j][i];

    for(int i = 1; i <= n; i++) buff2[i] += buff2[i-1];

    for(int i = 1; i <= n; i++) arr[i] += buff2[i];

    storage.clear();
}

void process()
{
    size_t SQRT = (size_t)sqrt(n);
    while(q--)
    {
        int cmd, l, r; cin >> cmd >> l >> r;
        if(cmd == 0)
        {
            cout << query(l, r) << endl;
        }
        else
        {
            storage.emplace_back((cmd == 1? 1 : -1), l, r);
            if(storage.size() >= SQRT)
                flush();
        }
    }
}

