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
    cin >> n >> k >> str;
}

void process()
{
    vector<int> cnt[26];  // cnt[char][pos] = num;
    for(int i = 0; i < 26; i++) cnt[i].resize(k, 0);
    for(int i = 0; i < n; i += k)
    {
        for(int j = i; j < i+k; j++)
        {
            int idx = str[j]-'a';
            cnt[idx][j-i]++;
        }
    }
    string period(k, 'a');
    for(int i = 0; i < k; i++)
    {
        int sum[26] = {0};
        for(int c = 0; c < 26; c++)
            sum[c] += cnt[c][i] + (k-i-1 == i? 0 : cnt[c][k-i-1]);
        period[i] = max_element(sum, sum+26)-sum + 'a';
    }
    int ans = 0;
    for(int i = 0; i < n; i += k)
        for(int j = i; j < i+k; j++)
            if(str[j] != period[j-i])
                ans++;
    cout << ans << endl;
}

