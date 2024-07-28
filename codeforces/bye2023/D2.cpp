#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Key = multiset<int>;

vector<vector<int>> table {
 /* 1 */ vector<int>{1}, 
 /* 3 */ vector<int>{13,14,31},
 /* 5 */ vector<int>{103,130,140,247,301,310}, 
 /* 7 */ vector<int>{1003,1030,1300,1400,2470,3001,3010,3100}, 
 /* 9 */ vector<int>{10473,13164,14463,14487,16944,17274,17853,19563,26073,28164,31494,31596},
 /* 11 */ vector<int>{100287,101037,104208,113748,116064,118260,118536,121695,123630,123732,125430,127293,127968,130575,131172,131703,132402,133002,136005,141897,143652,144402,144429,144558,146760,147492,151836,151926,156810,158379,159630,160353,160854,161028,161049,164052,164328,164496,167049,168498,168534,172494,173967,174387,175584,175791,178347,179052,180720,186816,187197,187209,187749,188682,189492,190023,190230,191847,192402,192405,193770,194895,195690,196005,196290,198009,200133,200763,202326,203160,203967,204336,208995,212223,212346,212676,213051,220503,220686,222195,224058,225177,225993,228870,230019,230190,231780,232311,234096,234111,234390,239601,242370,242760,244149,244410,245061,248070,249033}
};

map<Key, vector<int>> mp;
vector<Key> ans(100);

Key get_key(LL num) {
    Key k;
    while (num != 0) {
        k.insert(num % 10);
        num /= 10;
    }
    return k;
}

void preprocess() {
    int biggest_size = 0;
    LL num = 1;
    while (biggest_size < 99) {
        Key k = get_key(num * num);
        auto &v = mp[k];
        v.emplace_back(num);

        /*
        cerr << "num = " << num << ", num2 = " << num * num << ", k = ";
        for (auto x : k) cerr << x << " ";
        cerr << endl;
        */

        biggest_size = max(biggest_size, (int)v.size());
        if (v.size() >= 99) {
            cerr << "num = " << num << ", num2 = " << num * num << ", sz = " << v.size() << endl;
        }
        if (k.size() < 100 && v.size() >= k.size() && v.size() > ans[k.size()].size()) {
            ans[k.size()] = k;
        }
        num++;
    }
}

void solve() {
    for (int i = 1; i < 100; i += 2) {
        cerr << "i = " << i << ", key = ";
        for (auto x : ans[i]) cerr << x << " ";
        cerr << ", vals = ";
        for (auto x : mp[ans[i]]) cerr << x << " ";
        cerr << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    preprocess();
    int T; cin >> T;
    while (T--) solve();
}

