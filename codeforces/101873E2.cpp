// detecting negative cycle using floyd warshall, dead
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<double, int> Edge;
#define w first
#define idx second

const int N = 802;
const double INF = 1e9;

int vn, en;
double dist[N][N];

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

void init()
{
    cin >> vn >> en;
    for(int i = 1; i <= vn; i++)
        for(int j = 1; j <= vn; j++)
            dist[i][j] = INF;
    for(int i = 0; i < en; i++)
    {
        int from, to; double w; cin >> from >> to >> w;
        dist[from][to] = -log(w);
    }
}

bool negativeCycle()  // using floyd warshall
{
    for(int k = 1; k <= vn; k++)
        for(int i = 1; i <= vn; i++)
            for(int j = 1; j <= vn; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i = 1; i <= vn; i++) 
        if(dist[i][i] < 0) return true;
    return false;
}

void process()
{
    if(negativeCycle()) cout << "inadmissible" << endl;
    else cout << "admissible" << endl;
}

