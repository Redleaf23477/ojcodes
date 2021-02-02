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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int vn, en;
using Edge = tuple<LL,LL>; // (w, v)
vector<vector<Edge>> graph;
// three layer: 
//  1. normal graph
//  2. after add
//  3. after substract
//  4. after add & substract

void init() {
    cin >> vn >> en;
    graph.assign(4*vn, vector<Edge>());
    for (int i = 0; i < en; i++) {
        // for undirected edge (u, v), build them as two directed edges
        // for each directed edge: (u -> v)
        int u, v, w; cin >> u >> v >> w; u--, v--;
        // (u) -(w)-> (v) : on same layer
        for (int i = 0; i < 4; i++) {
            graph[vn*i+u].emplace_back(w, vn*i+v);
            graph[vn*i+v].emplace_back(w, vn*i+u);
        }
        // (u) -(2w)-> (v) : add
        graph[u].emplace_back(2*w, vn+v);
        graph[v].emplace_back(2*w, vn+u);
        graph[vn*2+u].emplace_back(2*w, vn*3+v);
        graph[vn*2+v].emplace_back(2*w, vn*3+u);
        // (u) -(0)-> (v) : substract
        graph[u].emplace_back(0, vn*2+v);
        graph[v].emplace_back(0, vn*2+u);
        graph[vn+u].emplace_back(0, vn*3+v);
        graph[vn+v].emplace_back(0, vn*3+u);
        // (u) -(w)-> (v) : add & substract
        graph[u].emplace_back(w, vn*3+v);
        graph[v].emplace_back(w, vn*3+u);

    }
}

void process() {
    const LL INF = 1ll << 60;
    vector<LL> dist(4*vn, INF); {
        auto dijk = [&](int u) -> void {
            dist[u] = 0;
            priority_queue<Edge, vector<Edge>, greater<Edge>> pq; pq.emplace(0, u);
            while (!pq.empty()) {
                auto [len, u] = pq.top(); pq.pop();
                if (dist[u] < len) continue;
                dist[u] = len;
                for (auto [w, v] : graph[u]) {
                    if (len + w < dist[v]) {
                        dist[v] = len + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
        };
        dijk(0);
    }
    for (int i = 1; i < vn; i++) cout << dist[3*vn+i] << " ";
    cout << endl;
}

