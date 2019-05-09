//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct Peo
{
    int x, y;
    char dir;
};

int pn, Q, X, Y;
vector<Peo> arr;
vector<int> x2ori, y2ori;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void dox()
{
    int idx = 0;
    set<int> s;
    map<int, int> mp;
    s.insert(0);
    for(auto &p:arr) 
    {
        if(p.dir == 'E') p.x = p.x+1;
        else if(p.dir == 'W') p.x = p.x-1;
        s.insert(p.x);
    }
    for(auto pos:s)
    {
        mp[pos] = idx;
        x2ori[idx] = pos;
        idx++;
    }
    for(auto &p:arr)
    {
        p.x = mp[p.x];
    }
    X = idx;
}
void doy()
{
    int idx = 0;
    set<int> s;
    map<int, int> mp;
    s.insert(0);
    for(auto &p:arr) 
    {
        if(p.dir == 'N') p.y = p.y+1;
        else if(p.dir == 'S') p.y = p.y-1;
        s.insert(p.y);
    }
    for(auto pos:s) 
    {
        mp[pos] = idx;
        y2ori[idx] = pos;
        idx++;
    }
    for(auto &p:arr)
    {
        p.y = mp[p.y];
    }
    Y = idx;
}

void init()
{
    cin >> pn >> Q;
    arr.resize(pn);
    x2ori.resize(pn), y2ori.resize(pn);
    for(int i = 0; i < pn; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].dir;
    }
    dox();
    doy();
}

void process()
{
    int sum[505][505];
    memset(sum, 0, sizeof(sum));
    for(auto p : arr)
    {
        if(p.dir == 'N')
        {
            for(int x = 0; x <= X; x++)
                for(int y = p.y; y <= Y; y++)
                    sum[x][y]++;
        }
        else if(p.dir == 'S')
        {
            for(int x = 0; x <= X; x++)
                for(int y = p.y; y >= 0; y--)
                    sum[x][y]++;
        }
        else if(p.dir == 'E')
        {
            for(int x = p.x; x <= X; x++)
                for(int y = 0; y <= Y; y++)
                    sum[x][y]++;
        }
        else
        {
            for(int x = p.x; x >= 0; x--)
                for(int y = 0; y <= Y; y++)
                    sum[x][y]++;
        }
    }
    ll mxx = -1, mxy = -1, mx = 0;
    for(int x = 0; x <= X; x++)
        for(int y = 0; y <= Y; y++)
        {
            if(sum[x][y] > mx) mxx = x, mxy = y, mx = sum[x][y];
            else if(sum[x][y] == mx)
            {
                if(x < mxx) mxx = x, mxy = y, mx = sum[x][y];
                else if(x == mxx && y < mxy) mxx = x, mxy = y, mx = sum[x][y];
            }
        }
//    cout << mxx << " " << mxy << " " << sum[mxx][mxy] << endl;
    cout << x2ori[mxx] << " " << y2ori[mxy] << endl;
}

