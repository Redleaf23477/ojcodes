//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

ll n, q;
int mp[2][N];

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
    cin >> n >> q;
}

bool legal(int x) { return 0 <= x && x < n; }

void process()
{
    int r, c;
    ll bad = 0;
    while(q--)
    {
        cin >> r >> c;
        r--, c--;
        if(mp[r][c] == 1)
        {
            for(int i = -1; i <= 1; i++)
            {
                if(legal(c+i) && mp[1-r][c+i] == 1) bad--;
            }
        }
        else
        {
            for(int i = -1; i <= 1; i++)
            {
                if(legal(c+i) && mp[1-r][c+i] == 1) bad++;
            }
        }
        mp[r][c] = 1-mp[r][c];
        if(bad) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

