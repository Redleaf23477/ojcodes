// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll bag, m;
ll cut;
vector<ll> box;

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
    cin >> bag >> m;
    cut = 0;
    box.resize(64, 0);
    fill(box.begin(), box.end(), 0);
    for(int i = 0; i < m; i++)
    {
        ll x; cin >> x;
        ll pw = 0;
        while(x) x>>=1, pw++;
        box[pw-1]++;
    }
}

bool borrow(int pos)
{
    if(pos == 63) return false;
    if(box[pos+1] == 0)
    {
        bool res = borrow(pos+1);
        if(res == false) return false;
    }
    box[pos+1]--;
    box[pos] += 2;
    cut++;
    return true;
}

void process()
{
    bool good = true;
    for(int i = 0; i < 64 && good; i++)
    {
        if((bag>>i)&1)
        {
            if(box[i] == 0)
            {
                bool res = borrow(i);
                if(res == false) good = false;
            }
            box[i]--;
        }
        // make big
        while(box[i] >= 2) box[i+1]++, box[i] -= 2;
    }
    if(good) cout << cut << endl;
    else cout << -1 << endl;
}

