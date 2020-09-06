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

int R, C;
map<ll, vector<tuple<int,int>>> mp;

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
    cin >> R >> C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            ll x; cin >> x;
            mp[x].emplace_back(r, c);
        }
}

void process()
{
    vector<ll> row(R, 0), col(C, 0);
    for(auto [h, arr] : mp)
    {
        vector<ll> new_h(arr.size(), 0);
        map<ll, vector<int>> gr, gc;
        // cal height
        for(size_t i = 0; i < arr.size(); i++)
        {
            auto [r, c] = arr[i];
            new_h[i] = max(row[r], col[c]) + 1;
            gr[r].emplace_back(i), gc[c].emplace_back(i);
        }
        // bfs sync
        vector<int> tmp(arr.size()); for(size_t i = 0; i < tmp.size(); i++) tmp[i] = i;
        sort(tmp.begin(), tmp.end(), [&](int i, int j) { return new_h[i] > new_h[j]; });
        set<int> rvis, cvis;
        for(auto x : tmp)
        {
            if(rvis.count(get<0>(arr[x]))) continue;
            if(cvis.count(get<1>(arr[x]))) continue;
            queue<int> q ({x});
            while(!q.empty())
            {
                auto [r, c] = arr[q.front()]; q.pop();
                if(rvis.count(r) == 0)
                    for(auto y : gr[r])
                    {
                        new_h[y] = new_h[x];
                        q.emplace(y);
                    }
                if(cvis.count(c) == 0)
                    for(auto y : gc[c])
                    {
                        new_h[y] = new_h[x];
                        q.emplace(y);
                    }
                rvis.insert(r), cvis.insert(c);
            }
        }
        
        // write back
        for(size_t i = 0; i < arr.size(); i++)
        {
            auto [r, c] = arr[i];
            row[r] = max(row[r], new_h[i]);
            col[c] = max(col[c], new_h[i]);
        }
    }
    auto mx = [](vector<ll> &arr) { return *max_element(arr.begin(), arr.end()); };
    cout << max(mx(row), mx(col)) << endl;
}

