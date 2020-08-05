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
using P = pair<ll,ll>;
#define red first
#define blue second

ll n, k;
vector<P> arr;

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
    cin >> n >> k;
    arr.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i].red >> arr[i].blue;
}

void process()
{
    //pre: separate trees with (red+blue < k)
    //enum: how many boxes filled with a tree
    //greedy: how many boxes can be filled with red/blue only
}

