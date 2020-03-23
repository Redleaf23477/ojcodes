// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;
using P = pair<int,int>;
#define x first
#define y second

ll n, m, k;
vector<P> s, e;


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
    cin >> n >> m >> k;
    s.resize(k), e.resize(k);
    for(int i = 0; i < k; i++)
    {
        cin >> s[i].x >> s[i].y;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> e[i].x >> e[i].y;
    }
}

void process()
{
    string ans;
    for(int i = 1; i < n; i++) ans.push_back('U');
    for(int i = 1; i < m; i++) ans.push_back('L');

    for(int r = 1; r < n; r++)
    {
        char dir = (r%2 == 1? 'R' : 'L');
        for(int c = 1; c < m; c++)
            ans.push_back(dir);
        ans.push_back('D');
    }
    for(int c = 1; c < m; c++)
        ans.push_back(n%2 == 1? 'R' : 'L');

    cout << ans.size() << endl;
    cout << ans << endl;
}

