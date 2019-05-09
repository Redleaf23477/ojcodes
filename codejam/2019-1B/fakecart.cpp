//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 15;
int pn, Q;
int sum[N][N];

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
    memset(sum, 0, sizeof(sum));
    cin >> pn >> Q;
}

void process()
{
    for(int i = 0; i < pn; i++)
    {
        int px, py; char dir; cin >> px >> py >> dir;
        if(dir == 'N')
        {
            for(int x = 0; x < N; x++)
                for(int y = py+1; y < N; y++)
                    sum[x][y]++;
        }
        else if(dir == 'S')
        {
            for(int x = 0; x < N; x++)
                for(int y = py-1; y >= 0; y--)
                    sum[x][y]++;
        }
        else if(dir == 'E')
        {
            for(int x = px+1; x < N; x++)
                for(int y = 0; y < N; y++)
                    sum[x][y]++;
        }
        else 
        {
            for(int x = px-1; x >= 0; x--)
                for(int y = 0; y < N; y++)
                    sum[x][y]++;
        }
    }
    int mxx = -1, mxy = -1, mx = -1;
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
        {
            if(sum[x][y] > mx) mxx = x, mxy = y, mx = sum[x][y];
            if(sum[x][y] == mx && x < mxx) mxx = x, mxy = y, mx = sum[x][y];
            if(sum[x][y] == mx && x == mxx && y < mxy) mxx = x, mxy = y, mx = sum[x][y];
        }
    cout << mxx << " " << mxy << endl;
}

