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
ll sum, rd;
vector<vector<ll>> arr, brr;
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
    sum = 0, rd = 0;
    for(int r = 0; r < R; r++)
    {
        arr[r].resize(C);
        for(int c = 0; c < C; c++)
        {
            cin >> arr[r][c];
            sum += arr[r][c];
        }
    }
    gg.resize(R*C, R*C);
}

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};

bool legal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

bool runKill()
{
    brr = arr;
    bool kill = false;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == -1) continue;
            ll acc = 0, cnt = 0;
            for(int d = 0; d < 4; d++)
            {
                int rr = r+dr[d], cc = c+dc[d];
                while(legal(rr, cc))
                {
                    if(arr[rr][cc] != -1)
                    {
                        acc += arr[rr][cc];
                        cnt++;
                        break;
                    }
                    rr += dr[d], cc += dc[d];
                }
            }
            if(arr[r][c] * cnt < acc)
            {
                brr[r][c] = -1;
                sum -= arr[r][c];
                kill = true;
            }
        }
    arr = brr;
    return kill;
}

void process()
{
    ll ans = 0;
    while(true)
    {
        ans += sum;
        cerr << var(sum) << endl;
        /*
        for(int r = 0; r < R; r++)
            for(int c= 0; c < C; c++)
            {
                cout << arr[r][c] << " \n"[c==C-1];
            }
            */
        if(runKill() == 0) break;
    }
    cout << ans << endl;
}
