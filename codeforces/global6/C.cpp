//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 505;

int R, C;
ll arr[N][N];

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
    cin >> R >> C;
}

ll lcm(ll lhs, ll rhs)
{
    return lhs * rhs / __gcd(lhs, rhs);
}

bool validate()
{
    set<ll> s;
    for(int r = 0; r < R; r++)
    {
        ll x = arr[r][0];
        for(int c = 1; c < C; c++)
        {
            x = __gcd(x, arr[r][c]);
        }
        if(s.count(x) != 0) return false;
        s.insert(x);
    }
    for(int c = 0; c < C; c++)
    {
        ll x = arr[0][c];
        for(int r = 1; r < R; r++)
        {
            x = __gcd(x, arr[r][c]);
        }
        if(s.count(x) != 0) return false;
        s.insert(x);
    }
    return true;
}

void process()
{
    if(R == 1 && C == 1) { cout << 0 << endl; return; }
    if(R < C)
    {
        // row : 1 ~ R
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
                arr[r][c] = r+1;
        }
        // col : R+1 ~ R+C
        for(int c = 0; c < C; c++)
        {
            for(int r = 0; r < R; r++)
                arr[r][c] = lcm(arr[r][c], R+c+1);
        }
    }
    else
    {
        for(int c = 0; c < C; c++)
            for(int r = 0; r < R; r++)
                arr[r][c] = c+1;
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                arr[r][c] = lcm(arr[r][c], C+r+1);
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cout << arr[i][j] << " \n"[j==C-1];
//    if(validate() == false) cout << "WA on " << R << ", " << C  << endl;
}

