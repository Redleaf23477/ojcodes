// by redleaf23477
// offline method
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;
using Pos = pair<int,int>;
#define r first
#define c second

struct Query { int r1, c1, r2, c2, ans; };


const int N = 501;

ll R, C, Q;
char arr[N][N];
ll logo[N][N];
vector<Query> query;
vector<Pos> pos[N];

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

inline bool isLegal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

inline bool checkColor(int r, int c, int dr, int dc, int len, char color)
{
    for(int i = 0; i < len; i++)
        if(!isLegal(r+i*dr, c+i*dc) || arr[r+i*dr][c+i*dc] != color)
            return false;
    return true;
}

ll getLogoSize(int r, int c)
{
    for(ll len = 1; len < R; len++)
    {
        bool good = true;

        // red
        good &= checkColor(r-len+1, c-len+1, 0, 1, len, 'R');
        good &= checkColor(r-len+1, c-len+1, 1, 0, len, 'R');
        // green 
        good &= checkColor(r-len+1, c+1, 0, 1, len, 'G');
        good &= checkColor(r-len+1, c+1, 1, 0, len, 'G');
        // yellow 
        good &= checkColor(r+1, c-len+1, 0, 1, len, 'Y');
        good &= checkColor(r+1, c-len+1, 1, 0, len, 'Y');
        // blue
        good &= checkColor(r+1, c+1, 0, 1, len, 'B');
        good &= checkColor(r+1, c+1, 1, 0, len, 'B');

        if(good == false) return len-1;
    }
    // unreachable
    return -1;
}

void init()
{
    cin >> R >> C >> Q;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> arr[r][c];
    query.resize(Q);
    for(int i = 0; i < Q; i++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        query[i] = (Query){a-1, b-1, c-1, d-1, 0};
    }
    // find all logo
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            logo[r][c] = getLogoSize(r, c);
            if(logo[r][c] > 0) pos[logo[r][c]].emplace_back(r, c);
        }
    /*
    cerr << "found logos" << endl;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cerr << logo[r][c] << " \n"[c==C-1];
    for(int len = 0; len < R; len++)
        if(pos[len].size() > 0)
        {
            cerr << var(len) << " : ";
            for(auto p : pos[len]) cerr << "(" << p.r << "," << p.c << ") ";
            cerr << endl;
        }
   */ 
}

int sum[N][N], tmp[N][N];
void solve(int len)
{
    // 2D prefix sum, turn to 1-index
    for(auto p : pos[len])
        tmp[p.r+1][p.c+1]++;
    for(int r = 0; r <= R; r++)
        for(int c = 0; c <= C; c++)
            sum[r][c] = tmp[r][c];
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            sum[r][c] += sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1];
    /*
    cerr << "sum " << var(len) << " : " << endl;
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            cerr << sum[r][c] << " \n"[c==C];
    */ 
    // check for all query
    for(auto &q : query)
    {
        if(q.ans > 0) continue;
        int r1 = 1+q.r1+len-1, r2 = 1+q.r2-len, c1 = 1+q.c1+len-1, c2 = 1+q.c2-len;
        if(r1 <= r2 && c1 <= c2)
        {
            if(sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1] > 0)
            {
                /*
                cerr << "found " << var(len) << " for query " << var(q.r1) << var(q.c1) << var(q.r2) << var(q.c2) << endl;
                */
                q.ans = 4*len*len;
            }
        }
    }
}

void process()
{
    for(int len = min(R, C)/2; len > 0; len--)
        solve(len);
    for(auto q : query)
        cout << q.ans << endl;
}

