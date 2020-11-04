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

ifstream fin("coffee.in");

#define cin fin

void init();
void process();

int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int c, p;
map<string, map<string, int>> mp;

void init()
{
    cin >> c >> p;
    string arr[] = {"small", "medium", "large"};
    for(int i = 0; i < c; i++)
    {
        string coffee; cin >> coffee;
        map<string, int> tmp;
        for(int j = 0; j < 3; j++)
        {
            int x; cin >> x;
            tmp[arr[j]] = x;
        }
        mp[coffee] = tmp;
    }
}

void process()
{
    int fee = 100/p;
    for(int i = 0; i < p; i++)
    {
        string name, size, coffee; 
        cin >> name >> size >> coffee;
        int ans = fee + mp[coffee][size];
        if((ans+1)%5 == 0) ans = ans+1;
        else if((ans-1)%5 == 0) ans = ans-1;
        cout << name << " " << ans << endl;
    }
}

