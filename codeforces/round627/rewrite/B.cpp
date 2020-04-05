// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

int n;
vector<ll> pos;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    pos.resize(n+1);
    fill(pos.begin(), pos.end(), -1);
}

void process()
{
    bool good = false;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(pos[x] == -1) pos[x] = i;
        else if(i - pos[x] + 1 >= 3) good = true;
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

