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
string str;

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
    cin >> str;
    n = str.size();
}

void process()
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        int c = str[i] - '0';
        while(num < c)
        {
            cout << "("; num++;
        }
        while(num > c)
        {
            cout << ")"; num--;
        }
        cout << str[i];
        num = c;
    }
    while(num--) cout << ")";
    cout << endl;
}

