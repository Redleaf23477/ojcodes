//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 55;

int W, H, n;
int ans, highest;
vector<tuple<int,int,int>> pt;
int arr[N][N];
bool locked[N][N];

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
    cin >> W >> H >> n;
    ans = 0;
    highest = -7122;
    memset(locked, 0, sizeof(locked));
    for(int i = 0; i < n; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        x--, y--;
        highest = max(highest, z);
        locked[x][y] = true;
        pt.emplace_back(x, y, z);
    }
}

bool valid_start()
{
    for(int i = 0; i < n; i++)
    {
        int x1, y1, z1;
        tie(x1, y1, z1) = pt[i];
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            int x2, y2, z2;
            tie(x2, y2, z2) = pt[j];
            int d12 = abs(x1-x2)+abs(y1-y2);
            if(d12 < abs(z1-z2)) return false;
            for(int k = 0; k < n; k++)
            {
                if(k == i || k == j) continue;
                int x3, y3, z3;
                tie(x3, y3, z3) = pt[k];
                int d13 = abs(x1-x3)+abs(y1-y3);
                if(d13 < abs(z1-z3)) return false;
                int d23 = abs(x2-x3)+abs(y2-y3);
                if(d23 < abs(z2-z3)) return false;
            }
        }
    }
    return true;
}

void fill()
{
    for(int x = 0; x < W; x++)
        for(int y = 0; y < H; y++)
            arr[x][y] = highest;
    ans = W*H*highest;
}

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return 0 <= x && x < W && 0 <= y && y < H;
}

void bfs_dig(int x, int y, int z)
{
    queue<tuple<int,int,int>> q;
    q.emplace(x, y, z);
    while(!q.empty())
    {
        tie(x, y, z) = q.front(); q.pop();
        if(z >= arr[x][y]) continue;
        ans -= arr[x][y]-z;
        arr[x][y] = z;
        for(int d = 0; d < 4; d++)
        {
            int nx = x+dx[d], ny = y+dy[d];
            if(valid(nx, ny) && z+1 < arr[nx][ny]) q.emplace(nx, ny, z+1);
        }
    }
}

bool drop(int x, int y)
{
    int nz = arr[x][y]-1;
    bool flg = true;
    for(int d = 0; d < 4; d++)
    {
        int nx = x+dx[d], ny = y+dy[d];
        if(valid(nx, ny))
            if(abs(arr[nx][ny]-nz) > 1) flg = false;
    }
    if(flg) arr[x][y]--, ans--;
    return flg;
}

void process()
{
    if(!valid_start()) cout << "No" << endl;
    else
    {
        fill();
        int x, y, z;
        for(auto t : pt)
        {
            tie(x, y, z) = t;
            bfs_dig(x, y, z);
        }
        bool flg = true;
        while(flg)
        {
            flg = false;
            for(int x = 0; x < W; x++)
                for(int y = 0; y < H; y++)
                {
                    if(locked[x][y]) continue;
                    flg |= drop(x, y);
                }
        }
        cout << ans << endl;
        /*
        for(int y = 0; y < H; y++)
            for(int x = 0; x < W; x++)
                cout << arr[x][y] << " \n"[x==W-1];
        */
    }
}

