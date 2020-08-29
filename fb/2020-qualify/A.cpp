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

const int N = 55;

int n;
int graph[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t+1 << ":" << endl;
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j =0 ; j < n; j++)
            graph[i][j] = true;
    // in
    for(int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        if(ch == 'N') for(int j = 0; j < n; j++)
            graph[j][i] = false;
    }
    // out
    for(int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        if(ch == 'N') for(int j = 0; j < n; j++)
            graph[i][j] = false;
    }
}

bool vis[N];
bool go(int s, int t)
{
    if(s == t) return true;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s); vis[s] = true;
    int nei[] = {1, -1};
    while(!q.empty())
    {
        int f = q.front(); q.pop();
        for(int i = 0; i < 2; i++)
        {
            int nx = f + nei[i];
            if(nx < 0 || nx >= n) continue;
            if(graph[f][nx] == false) continue;
            if(vis[nx] == true) continue;
            vis[nx] = true;
            q.push(nx);
            if(nx == t) return true;
        }
    }
    return false;
}

void process()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(go(i, j)) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }
}

