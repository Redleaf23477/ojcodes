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
    cin >> str;
}

bool isSame(string &s)
{
    char ch = s[0];
    for(auto c : s)
        if(c != ch) return false;
    return true;
}

string turn(string &s)
{
    string ans;
    char ch[] = {'0', '1'};
    int idx = s[0] - '0';
    for(auto c : s)
    {
        if(c == ch[idx])
        {
            ans.push_back(c);
            idx = 1-idx;
        }
        else
        {
            ans.push_back(ch[idx]);
            ans.push_back(c);
        }
    }
    return ans;
}

void process()
{
    if(isSame(str))
    {
        cout << str << endl;
    }
    else 
    {
        cout << turn(str) << endl;
    }
}

