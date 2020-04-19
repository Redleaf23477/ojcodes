// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

struct Node
{
    ll r, c, idx;
    ll val;
};

bool cmp (const Node &lhs, const Node &rhs)
{
    return lhs.val > rhs.val;
}

ll R, C;
ll endRd;
vector<vector<ll>> arr;
vector<Node> peo;
vector<ll> gg;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> C;
    arr.resize(R);
    peo.clear();
    gg.clear();
    endRd = 1;
    for(int r = 0; r < R; r++)
    {
        arr[r].resize(C);
        for(int c = 0; c < C; c++)
        {
            cin >> arr[r][c];
            peo.push_back((Node){r, c, r*C+c, arr[r][c]});
        }
    }
    gg.resize(R*C, R*C);
    sort(peo.begin(), peo.end(), cmp);
}

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};

bool legal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

void runKill(Node &p)
{
    for(int d = 0; d < 4; d++)
    {
        int r = p.r + dr[d], c = p.c + dc[d];
        for(ll rd = 1; rd <= gg[p.idx] && legal(r, c); r += dr[d], c += dc[d])
        {
            if(arr[r][c] > p.val) break;
            if(arr[r][c] == p.val)
            {
                if(rd == R*C) break;
                else { rd = gg[r*C+c]; continue; }
            }
            if(rd <= gg[r*C+c])
            {
                gg[r*C+c] = rd;
                rd++;
            }
            endRd = max(endRd, rd);
        }
    }
}

void process()
{
    for(auto p : peo)
    {
        runKill(p);
    }
    cout << "gg" << endl;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            cout << gg[r*C+c] << " ";
        }
        cout << endl;
    }
    cerr << var(endRd) << endl;
    ll ans = 0;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(gg[r*C+c] == R*C) gg[r*C+c] = endRd;
            ans += arr[r][c] * gg[r*C+c];
        }
    }
    cout << ans << endl;
}

