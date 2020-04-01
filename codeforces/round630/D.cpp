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

const int N = 502;

int k;

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
    cin >> k;
}

void process()
{
    int R = 3, C = 4;
    int y = (1<<18)-1;
    int a = k;
    int b = 1<<17;
    int mat[3][4] = {
        {y, a, a, 0},
        {b, 0, a, 0},
        {b, b, y, k}
    };
    cout << R << " " << C << endl;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cout << mat[r][c] << " \n"[c==C-1];
}

