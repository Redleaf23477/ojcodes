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

int n;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
}

void process()
{
    int arr[6];
    for(int i = 0; i < 6; i++)
        arr[i] = (n>>(5-i))&1;
    int ans[6] = {
        arr[0],
        arr[5],
        arr[3],
        arr[2],
        arr[4],
        arr[1]
    };
    /*
    for(int i = 0; i < 6; i++)
        cout << ans[i] << endl;
    */
    int out = 0;
    for(int i = 0; i < 6; i++)
        out |= (ans[i]? 1<<(5-i) : 0);
    cout << out << endl;
}

