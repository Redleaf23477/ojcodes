// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

void init();
void process();

int n;
string str;
int L, R;
vector<bool> pspalin;

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
    n = str.size();
    pspalin.resize(n); fill(pspalin.begin(), pspalin.end(), false);
    pspalin[0] = pspalin[n-1] = (str[0] == str[n-1]);
    if(pspalin[0] == false)
    {
        L = 0, R = n-1;
    }
    else
    {
        for(L = 1, R = n-2; L <= R; L++, R--)
        {
            pspalin[L] = pspalin[R] = (str[L] == str[R] && pspalin[L-1]);
            if(pspalin[L] == false)
            {
                break;
            }
        }
    }
    /*
    cout << "check : ";
    for(auto x : pspalin) cout << x;
    cout << endl;
    cout << var(L) << var(R) << endl;
    */
}

bool ispalin(int l, int r)
{
    while(l <= r)
    {
        if(str[l] == str[r]) l++, r--;
        else return false;
    }
    return true;
}

void process()
{
    int lmx = 0, rmx = 0;
    // from left
    for(int len = 1; len < (R-L+1); len++)
    {
        if(ispalin(L, L+len-1)) lmx = len;
    }
    // from right
    for(int len = 1; len < (R-L+1); len++)
    {
        if(ispalin(R-len+1, R)) rmx = len;
    }
    for(int l = 0; l < L; l++) cout << str[l];
    if(lmx > rmx)
    {
        for(int len = 0; len < lmx; len++) cout << str[L+len];
    }
    else
    {
        for(int len = rmx; len > 0; len--) cout << str[R-len+1];
    }
    for(int r = max(L, R+1); r < n; r++) cout << str[r];
    cout << endl;
}
