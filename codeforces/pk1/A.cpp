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
vector<int> arr;

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
    string str;
    while(cin >> str)
    {
        if(str[0] == 'p') arr.push_back(1);
        else arr.push_back(0);
    }
}

const int P = 1, I = 0;
int idx = 0;
stringstream ss;

bool f()
{
    bool res = true;
    if(idx == arr.size()) return false;
    int tok = arr[idx++];
    if(tok == P)
    {
        ss << "pair<";
        res &= f();
        ss << ",";
        res &= f();
        ss << ">";
    }
    else ss << "int";
    return res;
}

void process()
{
    bool res = f();
    if(idx == arr.size() && res == true)
    {
        string ans; ss >> ans;
        cout << ans << endl;
    }
    else
    {
        cout << "Error occurred" << endl;
    }
}
