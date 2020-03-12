#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

int n;
map<int, int> first, second;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    first.clear();
    second.clear();
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(first.count(x) == 0)
        {
            first[x] = i, second[x] = i;
        }
        first[x] = min(first[x], i);
        second[x] = max(second[x], i);
    }
}

void process()
{
    for(auto x : first)
    {
        if(second[x.first] - x.second > 1)
        {
//            cerr << var(x.first) << var(x.second) << var(second[x.first]) << endl;
            cout << "YES" << endl; return;
        }
    }
    cout << "NO" << endl;
}

