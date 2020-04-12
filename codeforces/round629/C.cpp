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

ll n;
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
    cin >> n >> str;
}

void process()
{
    string big(n, 'x'), small(n, 'x');
    bool same = true;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '0')
        {
            if(i != 0) big[i] = small[i] = '0';
            else big[i] = '2', small[i] = '1', same = false;
        }
        else if(str[i] == '1')
        {
            if(i == 0) big[i] = small[i] = '2';
            else
            {
                if(same) big[i] = '1', small[i] = '0', same = false;
                else big[i] = '0', small[i] = '1';
            }
        }
        else if(str[i] == '2')
        {
            if(same) big[i] = small[i] = '1';
            else big[i] = '0', small[i] = '2';
        }
    }
    cout << big << endl << small << endl;
}

