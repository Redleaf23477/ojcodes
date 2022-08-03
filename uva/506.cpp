#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();

    // mapping
    map<string,int> _str2idx;
    map<int,string> _idx2str;

    // graph
    vector<vector<int>> graph;

    // program installation state
    enum STATE {UNINSTALLED, EXPLICIT, IMPLICIT};
    vector<STATE> state;
    vector<int> install_order;
    vector<int> indeg;  // #progs depending on it

    // dealing with mapping
    auto str2idx = [&](string str) {
        if (_str2idx.count(str) == 0) {
            // insert to mapping
            int idx = _str2idx.size();
            _str2idx[str] = idx;
            _idx2str[idx] = str;
            // add entry to graph
            graph.emplace_back(vector<int>());
            indeg.emplace_back(0);
            state.emplace_back(UNINSTALLED);
        }
        return _str2idx[str];
    };
    auto idx2str = [&](int idx) {
        return _idx2str[idx];
    };

    // operations
    auto depend = [&](stringstream &ss) {
        // IO & build graph
        string prog; ss >> prog;
        int prog_idx = str2idx(prog);
        string dep;
        while (ss >> dep) {
            int dep_idx = str2idx(dep);
            graph[prog_idx].emplace_back(dep_idx);
        }
    };
    function<void(int)> dfs_install = [&](int u) {
        for (auto v : graph[u]) {
            indeg[v] += 1;
            if (state[v] == UNINSTALLED) {
                state[v] = IMPLICIT;
                dfs_install(v);
            }
        }
        cout << "   Installing " << idx2str(u) << "\n";
        install_order.emplace_back(u);
    };
    auto install = [&](stringstream &ss) {
        string prog; ss >> prog;
        int prog_idx = str2idx(prog);
        if (state[prog_idx] != UNINSTALLED) {
            cout << "   " << prog << " is already installed.\n";
        } else {
            state[prog_idx] = EXPLICIT;
            dfs_install(prog_idx);
        }
    };
    function<void(int)> dfs_remove = [&](int u) {
        cout << "   Removing " << idx2str(u) << "\n";
        for (auto v : graph[u]) {
            indeg[v] -= 1;
            if (state[v] == IMPLICIT && indeg[v] == 0) {
                state[v] = UNINSTALLED;
                dfs_remove(v);
            }
        }
    };
    auto remove = [&](stringstream &ss) {
        string prog; ss >> prog;
        int prog_idx = str2idx(prog);
        if (indeg[prog_idx] != 0) {
            cout << "   " << prog << " is still needed.\n";
        } else if (state[prog_idx] == UNINSTALLED) {
            cout << "   " << prog << " is not installed.\n";
        } else  {
            state[prog_idx] = UNINSTALLED;
            dfs_remove(prog_idx);
        }
    };
    auto list = [&]() {
        vector<bool> vis(graph.size(), false);
        vector<int> ans;
        for (auto it = install_order.rbegin(); it != install_order.rend(); it++) {
            if (state[*it] != UNINSTALLED && vis[*it] == false) {
                ans.emplace_back(*it);
                vis[*it] = true;
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto p : ans) {
            cout << "   " << idx2str(p) << "\n";
        }
    };

    string line; 
    while (getline(cin, line)) {
        // echo
        cout << line << "\n";
        // operation
        stringstream ss(line);
        string cmd; ss >> cmd;
        if (cmd == "DEPEND") depend(ss);
        else if (cmd == "INSTALL") install(ss);
        else if (cmd == "REMOVE") remove(ss);
        else if (cmd == "LIST") list();
        else if (cmd == "END") break;
        else assert(false && "unreachable");
    }
}

