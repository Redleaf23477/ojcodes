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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

LL d, k;

void init() {
    cin >> d >> k;
}

void process() {
    auto inCirc = [d] (LL x, LL y) { 
        return x*x + y*y <= d*d;
    };
    LL s = 0; {
        while (inCirc(k*s, k*s)) s++;
        s--;
    }
    LL t = 0; {
        while (inCirc(k*(s+t), k*s)) t++;
        t--;
    }
    if (t % 2 == 0) {
        cout << "Utkarsh" << endl;
    } else {
        cout << "Ashish" << endl;
    }
}

