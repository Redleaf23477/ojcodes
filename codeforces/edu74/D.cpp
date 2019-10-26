//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n;
string str;

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
    cin >> n >> str;
}

void process()
{
    ll ans = n * (n-1) / 2;
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        char ch = str[i];
        if(ch == 'A') 
        {
            if(b != 0) ans -= b, b = 0;
            a++;
            if(i - a >= 0 && a > 1) ans--; 
        }
        else if(ch == 'B')
        {
            if(a != 0) ans -= a, a = 0; 
            b++;
            if(i - b >= 0 && b > 1) ans--; 
        }
    }
    cout << ans << endl;
}

