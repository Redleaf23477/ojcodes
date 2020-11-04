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
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

vector<pair<int,int>> robot, light;

bool cmp(const pair<int,int> &lhs, const pair<int,int> &rhs)
{
    if(lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second < rhs.second;
}

void init()
{
    int n, m; cin >> n >> m;
    vector<pair<int,int>> rob(n), lig(m);
    for(auto &r : rob) cin >> r.first >> r.second;
    for(auto &l : lig) cin >> l.first >> l.second;
    sort(rob.begin(), rob.end(), cmp);
    sort(lig.begin(), lig.end(), cmp);

    for(auto l : lig)
    {
        while(!light.empty() && l.second >= light.back().second)
            light.pop_back();
        light.emplace_back(l);
    }

    for(auto r : rob)
    {
        if(robot.empty() || r.second < robot.back().second)
            robot.emplace_back(r);
    }
}

void process()
{
    vector<int> ans(1000006, 0);

    for(auto r : robot) for(auto l : light)
    {
        int dx = l.first - r.first;
        int dy = max(0, l.second + 1 - r.second);
        if(dx >= 0) ans[dx] = max(ans[dx], dy);
    }

    for(int i = ans.size()-2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);

    int ans2 = 2000006;
    for(int i = 0; i < (int)ans.size(); i++) ans2 = min(ans2, i+ans[i]);
    cout << ans2 << endl;
}
