// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

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

int R, C, q;
vector<vector<char>> arr;
int B_SIZE;
vector<vector<int>> blk;  // #blk x 2*C, each grid: (l, r)
vector<vector<int>> from; // R x 2*C

tuple<int,int> go(int r, int c)
{
    // index on grid map
    int gr = r, gc = c/2;
    // dir: 0 = left, 1 = right
    static const int DIR_L = 0;
    int dir = c - gc*2;
    // next (r, c) on grid map
    int nr = r, nc = c;

    // move
    if(arr[gr][gc] == '/')
    {
        if(dir == DIR_L) nc--;
        else nr++;
    }
    else
    {
        if(dir == DIR_L) nr++;
        else nc++;
    }

    // out of bounds
    if(nc < 0 || nc >= 2*C)
    {
        nr = nc = -1;
    }
    // if drop, re-cal dir
    else if(nr > r && nr < R)
    {
        if(arr[nr][gc] == '/') nc = gc*2;
        else nc = gc*2+1;
    }

    // if out of block, nc disregards dir
    return make_tuple(nr, nc);
}

void drop(int dr, int dc)
{
    int blkIdx = dr / B_SIZE;
    int sr = B_SIZE * blkIdx;
    int sc = 2*dc + (arr[sr][dc] != '/');
    int r = sr, c = sc;
    while(r < R && r < sr+B_SIZE)
    {
        from[r][c] = dc;
        auto [nr, nc] = go(r, c);
        // out of bounds
        if(nr == -1 || nc == -1)
        {
            r = c = -1;
            break;
        }
        // out of block
        if(nr == R || nr == sr+B_SIZE) 
        {
            break;
        }
        // stucked
        auto [nnr, nnc] = go(nr, nc);
        if(nnr == r && nnc == c)
        {
            c = -1; break;
        }
        r = nr, c = nc;
    }
    // store column on grid map
    blk[blkIdx][sc] = (c == -1? c : c/2);
}

void init()
{
    cin >> R >> C >> q;
    arr.assign(R, vector<char>(C));
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> arr[r][c];
    from.assign(R, vector<int>(2*C, -1));
    B_SIZE = (int)sqrt(R);
    blk.assign(R/B_SIZE + (R%B_SIZE != 0), vector<int>(2*C, -1));

    for(int r = 0; r < R; r += B_SIZE)
        for(int c = 0; c < C; c++)
            drop(r, c);
}

void clear(int dr, int dc)
{
    int blkIdx = dr / B_SIZE;
    int sr = blkIdx * B_SIZE;
    int sc = 2*dc + (arr[sr][dc] != '/');
    int r = sr, c = sc;
    while(r < R && r < sr + B_SIZE)
    {
        if(from[r][c] == -1) break;
        from[r][c] = -1;
        auto [nr, nc] = go(r, c);
        if(nr == -1 || nc == -1) break;
        // out of block
        if(nr == R || nr == sr+B_SIZE) 
        {
            break;
        }
        // stucked
        auto [nnr, nnc] = go(nr, nc);
        if(nnr == r && nnc == c)
        {
            c = -1; break;
        }
        r = nr, c = nc;
    }
    blk[blkIdx][sc] = -1;
}

void print_debug()
{
    cerr << "blk:" << endl;
    for(auto r : blk)
    {
        for(auto c : r)
            cerr << c << " ";
        cerr << endl;
    }
    cerr << "from:" << endl;
    for(auto r : from)
    {
        for(auto c : r)
            cerr << c << " ";
        cerr << endl;
    }
}

void process()
{
    while(q--)
    {
        int cmd, r, c; cin >> cmd;
        if(cmd == 1)
        {
            cin >> r >> c; r--, c--;
            // modify (r, 2*c-1), (r, 2*c), (r, 2*c+1), (r, 2*c+2)
            set<int> redrop;
            for(int i = -1; i <= 2; i++)
            {
                int cidx = 2*c+i;
                if(cidx >= 0 && cidx < 2*C) 
                {
                    if(from[r][cidx] != -1)
                        redrop.insert(from[r][cidx]);
                }
            }
            for(auto re_c : redrop) clear(r, re_c);
            arr[r][c] = (arr[r][c] == '/'? '\\' : '/');
            for(auto re_c : redrop) drop(r, re_c);
        }
        else
        {
            cin >> c; c--; 
            for(int r = 0; r < R && c != -1; r += B_SIZE)
            {
                int blkIdx = r / B_SIZE;
                c = blk[blkIdx][2*c + (arr[r][c] != '/')];
            }
            cout << (c == -1? c : c+1) << endl;
        }
    }
}

