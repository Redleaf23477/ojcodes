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

int n, k;
string str;

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
    cin >> n >> k;
    cin >> str;
    sort(str.begin(), str.end());
}

void process()
{
    vector<string> ans(k);
    for(int i = 0; i < k; i++) ans[i].push_back(str[i]);
    if(str[0] != str[k-1])
    {
        cout << ans.back() << endl;
        return;
    }
    if(str[k] == str.back())
    {
        for(int i = k; i < n; i++)
            ans[i%k].push_back(str[i]);
    }
    else 
    {
        ans[0].insert(ans[0].end(), str.begin()+k, str.end());
    }
    cout << ans[0] << endl;
}
