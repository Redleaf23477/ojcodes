//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 25;
int n;
map<int, int> mp;
vector<pair<int,int>> vec;
int mat[N][N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n*n; i++)
    {
        int x; cin >> x;
        if(mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
}

bool valid()
{
    int one = 0, two = 0, four = 0;
    for(auto x:mp)
    {
        int num = x.first, cnt = x.second;
        while(cnt >= 4) vec.emplace_back(4, num), cnt -= 4, four++;
        if(cnt >= 2) vec.emplace_back(2, num), cnt -= 2, two++;
        if(cnt >= 1) vec.emplace_back(1, num), cnt -= 1, one++;
    }
    if(n%2 == 0)
    {
        if(one || two) return false;
    }
    if(n%2 == 1)
    {
        if(one != 1) return false;
        if(two > n/2+n/2) return false;
    }
    return true;
}

void process()
{
    // corner: n = 1
    if(n == 1)
    {
        cout << "YES" << endl;
        cout << mp.begin()->first << endl;
        return;
    }
    /*
    // corner: n = 2
    if(n == 2)
    {
        if(mp.begin()->second != 4)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            int num = mp.begin()->first;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++) cout << num << " ";
                cout << endl;
            }
        }
        return;
    }
    */

    // normal
    if(!valid())
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(n%2 == 0)
    {
        int idx = 0;
        for(int i = 0; i < n/2; i++)
            for(int j = 0; j < n/2; j++)
            {
                int num = vec[idx++].second;
                mat[i][j] = mat[n-i-1][j] = mat[i][n-j-1] = mat[n-i-1][n-j-1] = num;
            }
    }
    else
    {
        sort(vec.begin(), vec.end());
        // put 1
        mat[n/2][n/2] = vec[0].second;
        // put 2
        int idx = 1;
        // horizontal
        for(int i = 0; i < n/2; i++)
        {
            if(vec[idx].first == 2)
            {
                mat[n/2][i] = mat[n/2][n-i-1] = vec[idx].second;
                idx++;
            }
            else
            {
                mat[n/2][i] = mat[n/2][n-i-1] = vec[idx].second;
                if(i != n/2-1)
                {
                    i++;
                    mat[n/2][i] = mat[n/2][n-i-1] = vec[idx].second;
                    idx++;
                }
                else
                {
                    vec[idx].first = 2;
                }
            }
        }
        // vertical
        for(int i = 0; i < n/2; i++)
        {
            if(vec[idx].first == 2)
            {
                mat[i][n/2] = mat[n-1-i][n/2] = vec[idx].second;
                idx++;
            }
            else
            {
                mat[i][n/2] = mat[n-1-i][n/2] = vec[idx].second;
                i++;
                mat[i][n/2] = mat[n-1-i][n/2] = vec[idx].second;
                idx++;
            }
        }
        
        // put 4
        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                if(mat[i][j] != 0) continue;
                int num = vec[idx++].second;
                mat[i][j] = mat[n-i-1][j] = mat[i][n-j-1] = mat[n-i-1][n-j-1] = num;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

