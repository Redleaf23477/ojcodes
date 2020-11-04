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
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    string str; cin >> str;
    vector<int> cnt(3, 0);
    int l = 0, r = 0, ans = 2*str.size();
    while(r < (int)str.size())
    {
        while(r < (int)str.size() && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0))
        {
            cnt[str[r]-'1']++;
            r++;
        }
        while(l < r && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
        {
            ans = min(ans, r-l);
            cnt[str[l]-'1']--;
            l++;
        }
    }
    if(ans == 2*str.size()) cout << 0 << endl;
    else cout << ans << endl;
}

