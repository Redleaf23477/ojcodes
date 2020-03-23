// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    ll len = 4;
    int cnt[5] = {0};
    for(int n = 0; n < 10000; n++)
    {
        int a = n%10, b = n/10%10, c = n/100%10, d = n/1000;
        if(a == b && b == c && c == d) cnt[4]++;
        else if((a == b && b == c) || (b == c && c == d)) cnt[3]++, cnt[1]++;
        else if(a == b)
        {
            if(c == d) cnt[2] += 2;
            else cnt[2] += 1, cnt[1] += 2;
        }
        else if(b == c) cnt[2] += 1, cnt[1] += 2;
        else if(c == d) cnt[2] += 1, cnt[1] += 2;
        else cnt[1] += 4;
    }
    for(int i = len; i > 0; i--) cout << cnt[i] << " ";
    cout << endl;
}

