// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;
using Pos = pair<int,int>;
#define r first
#define c second

struct Query { int r1, c1, r2, c2; };


const int N = 502;

ll R, C, Q;
char arr[N][N];
ll logo[N][N];
ll sum[N/2][N][N];
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
    return 1 <= r && r <= R && 1 <= c && c <= C;
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
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            cin >> arr[r][c];
    query.resize(Q);
    for(int i = 0; i < Q; i++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        query[i] = (Query){a, b, c, d};
    }
    // find all logo
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
        {
            logo[r][c] = getLogoSize(r, c);
            if(logo[r][c] > 0) pos[logo[r][c]].emplace_back(r, c);
        }
    /*
    cerr << "found logos" << endl;
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            cerr << logo[r][c] << " \n"[c==C];
    for(int len = 0; len < R; len++)
        if(pos[len].size() > 0)
        {
            cerr << var(len) << " : ";
            for(auto p : pos[len]) cerr << "(" << p.r << "," << p.c << ") ";
            cerr << endl;
        }
    */
}

void solve(int len)
{
    // 2D prefix sum
    for(auto p : pos[len])
        sum[len][p.r][p.c]++;
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            sum[len][r][c] += sum[len][r-1][c] + sum[len][r][c-1] - sum[len][r-1][c-1];
    if(len != min(R, C)/2)
    {
        for(int r = 1; r <= R; r++)
            for(int c = 1; c <= C; c++)
                sum[len][r][c] += sum[len+1][r][c];
    }
    /*
    cerr << "sum " << var(len) << " : " << endl;
    for(int r = 1; r <= R; r++)
        for(int c = 1; c <= C; c++)
            cerr << sum[len][r][c] << " \n"[c==C];
    */
}

void process()
{
    for(int len = min(R, C)/2; len > 0; len--)
        solve(len);
    for(auto q : query)
    {
        ll low = 1, high = min(q.r2-q.r1+1, q.c2-q.c1+1)/2, len, ans = 0;
        while(low <= high)
        {
            len = (low+high)/2;
            int r1 = q.r1+len-1, r2 = q.r2-len, c1 = q.c1+len-1, c2 = q.c2-len;
            if(r1 > r2 || c1 > c2) 
                high = len-1;
            else if(sum[len][r2][c2] - sum[len][r2][c1-1] - sum[len][r1-1][c2] + sum[len][r1-1][c1-1] > 0)
                ans = len, low = len+1;
            else 
                high = len-1;
        }
        cout << 4*ans*ans << endl;
    }
}


