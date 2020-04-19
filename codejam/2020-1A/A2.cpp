// by redleaf23477
// first case
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

int n;
vector<string> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    int mxLen = 0;
    for(auto x : arr) mxLen = max(mxLen, (int)x.size());
    for(int i = 0; i < n; i++)
    {
        string tmp(mxLen-arr[i].size(), '*');
        arr[i] = tmp + arr[i];
    }
    /*
    for(auto x : arr) cout << x << endl;
    */
    string ans;
    for(int i = 0; i < mxLen; i++)
    {
        int any = 0, nonzero = 0;
        vector<int> cnt(26, 0);
        for(auto x : arr)
        {
            if(isalpha(x[i])) cnt[x[i]-'A']++;
            else any++;
        }
        for(int i = 0; i < 26; i++) if(cnt[i] > 0) nonzero++;
        if(nonzero > 1) 
        {
            ans = "*"; break;
        }
        else if(nonzero == 1)
        {
            char ch = 'A' + max_element(cnt.begin(), cnt.end()) - cnt.begin();
            ans.push_back(ch);
        }
        else
        {
            continue;
        }
    }
    cout << ans << endl;
}

