//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define r first
#define c second

int R, C;
bool arr[30][30];

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

void init()
{
    cin >> R >> C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            arr[r][c] = 0;
}

void print(int r, int c) { cout << r+1 << " " << c+1 << endl; }

void fourXfour()
{
    print(1-1, 1-1);
    print(3-1, 2-1);
    print(2-1, 4-1);
    print(4-1, 3-1);
    print(2-1, 2-1);
    print(1-1, 4-1);
    print(3-1, 3-1);
    print(1-1, 2-1);
    print(3-1, 1-1);
    print(2-1, 3-1);
    print(4-1, 4-1);
    print(2-1, 1-1);
    print(4-1, 2-1);
    print(3-1, 4-1);
    print(1-1, 3-1);
    print(4-1, 1-1);
}

P run(int r, int c, vector<int> dr,  vector<int> dc)
{
    int idx = 0;
    P last(-1, -1);
    while(arr[r][c] == 0)
    {
        last = make_pair(r, c);
        print(r, c);
        arr[r][c] = 1;
        r = (r + dr[idx] + R)%R, c = (c + dc[idx] + C)%C;
        idx = (idx+1)%dr.size();
    }
    return last;
}

bool good(int r, int c, P last)
{
    if(last == P(-1, -1)) return true;
    if(r == last.r || c == last.c) return false;
    if(r + c == last.r + last.c) return false;
    if(r - c == last.r - last.c) return false;
    return true;
}

void process()
{
    if(R == 1 && C == 1)
    {
        cout << "POSSIBLE" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    if(R == 4 && C == 4)
    {
        cout << "POSSIBLE" << endl;
        fourXfour();
        return;
    }
    if(R == 2 && C == 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    if(R == 4 && C == 2)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    if(R < 4 && C < 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
    if(R < C)
    {
        P last(-1, -1);
        int r = 0;
        if(R%2 != 0)
        {
            last = run(0, 0, {2, -1, -1}, {1, 2, -2});
            r += 3;
        }
        for(; r < R; r += 2)
        {
            int c = 0;
            for(int i = 0; i < C; i++)
            {
                if(good(r, i, last)) { c = i; break; }
            }
            last = run(r, c, {1, -1}, {3, -2});
        }
    }
    else
    {
        P last(-1, -1);
        int c = 0;
        if(C%2 != 0)
        {
            last = run(0, 0, {1, 2, -2}, {2, -1, -1});
            c += 3;
        }
        for(; c < C; c+=2)
        {
//            cout << "!! " << c << endl;
            int r = 0;
            for(int i = 0; i < R; i++)
            {
                if(good(i, c, last)) { r = i; break; }
            }
            run(r, c, {3, -2}, {1, -1});
        }
    }

}

