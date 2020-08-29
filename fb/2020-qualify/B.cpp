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

int a, b;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t+1 << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    a = b = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        if(ch == 'A') a++;
        else b++;
    }
}

void process()
{
    tie(a, b) = make_tuple(a-min(a,b), b-min(a,b));
    if(abs(a-b) <= 1) cout << "Y" << endl;
    else cout << "N" << endl;
}
