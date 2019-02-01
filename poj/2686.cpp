//
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define w first
#define idx second

const int TN = 10;
const int VN = 50;
const int INF = (1<<30);

int n, m, p, a, b;
double ticket[TN];
double dp[(1<<TN)][VN];
vector<P> graph[VN];

void init();
void process();

int main()
{
    while(~scanf("%d %d %d %d %d", &n, &m, &p, &a, &b))
    {
        if(n == 0) break;
        init();
        process();
    }
    return 0;
}

void init()
{
    for(int i = 0; i <= m; i++) graph[i].clear();
    for(int i = 0; i < n; i++) scanf("%lf", &ticket[i]);
    for(int i = 0; i < p; i++)
    {
        int f, t, w; scanf("%d %d %d", &f, &t, &w);
        graph[f].push_back(P(w, t));
        graph[t].push_back(P(w, f));
    }
}

void process()
{
    for(int i = 0; i < (1<<n); i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = INF;
    dp[(1<<n)-1][a] = 0;

    for(int bag = (1<<n)-2; bag >= 0; bag--)
    {
        for(int u = 1; u <= m; u++)
        {
            for(vector<P>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
            {
                int v = it->idx, w = it->w;
                for(int t = 0; t < n; t++)
                {
                    if(((bag>>t)&1) != 0) continue;
                    if(dp[bag|(1<<t)][v] == INF) continue;
                    dp[bag][u] = min(dp[bag][u], dp[bag|(1<<t)][v]+w/ticket[t]);
                }
            }
        }
    }

    double mn = INF;
    for(int i = 0; i < (1<<n)-1; i++)
    {
        mn = min(mn, dp[i][b]);
    }
    if(mn == INF) printf("Impossible\n"); 
    else printf("%.5f\n", mn);
}

