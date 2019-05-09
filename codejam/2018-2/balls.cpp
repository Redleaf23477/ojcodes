///
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 105;

int n;
int arr[N];
int dest[N];
char mp[N][N];
int mxdepth;

void init();
void process();
void validate();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
//        validate();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    mxdepth = -7122;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) dest[i] = i;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mp[i][j] = '.';
}

bool leftmost_invalid() { return arr[0] == 0; }
bool rightmost_invalid() { return arr[n-1] == 0; }
bool total_invalid() 
{
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return sum != n;
}

void badcase(string msg)
{
//    cout << msg << " : ";
    cout << "IMPOSSIBLE" << endl;
}

void process()
{
    if(leftmost_invalid()) badcase("leftmost");
    else if(rightmost_invalid()) badcase("rightmost");
    else if(total_invalid()) badcase("total");
    else
    {
        // calculate destination
        vector<int> stat(arr, arr+n);
        queue<int> sufficient, insufficient;
        for(int i = 0; i < n; i++)
        {
            sufficient.push(i);
            if(arr[i] != 0) insufficient.push(i);
            while(!insufficient.empty())
            {
                int insuff = insufficient.front();
                while(!sufficient.empty())
                {
                    int f = sufficient.front(); sufficient.pop();
                    dest[f] = insuff;
                    if(--stat[insuff] == 0)
                    {
                        insufficient.pop();
                        break;
                    }
                }
                if(sufficient.empty()) break;
            }
        }

        /*
        for(int i = 0; i < n; i++) cout << dest[i] << " ";
        cout << endl;
        */

        // draw map
        mxdepth = -1;
        for(int i = 0; i < n; i++)
        {
            if(dest[i] == i) continue;
            else if(dest[i] < i)
            {
                for(int r = 0, c = i; c > dest[i]; r++, c--)
                    mp[r][c] = '/', mxdepth = max(mxdepth, r);
            }
            else 
            {
                for(int r = 0, c = i; c < dest[i]; r++, c++)
                    mp[r][c] = '\\', mxdepth = max(mxdepth, r);
            }
        }
        mxdepth += 2;

        // print ans;
        cout << mxdepth << endl;
        for(int r = 0; r < mxdepth; r++)
        {
            for(int c = 0; c < n; c++)
                cout << mp[r][c];
            cout << endl;
        }
    }
}

void validate()
{
    if(mxdepth < 0) return;
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++)
    {
        int r = 0, c = i;
        while(r <= mxdepth)
        {
            if(mp[r][c] == '\\')
            {
                assert(mp[r][++c] != '/');
            }
            else if(mp[r][c] == '/')
            {
                assert(mp[r][--c] != '\\');
            }
            r++;
        }
        res[c]++;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " "; 
    cout << endl;
    for(int i = 0; i < n; i++) cout << res[i] << " "; 
    cout << endl;
    /*
    for(int i = 0; i < n; i++)
    {
        assert(res[i] == arr[i]);
    }
    */
}

