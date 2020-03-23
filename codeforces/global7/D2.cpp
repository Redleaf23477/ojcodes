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

int prepalin(string s)
{
    string rev = s; reverse(rev.begin(), rev.end());
    s = s + '@' + rev;
    vector<int> fail(s.size());
    fail[0] = -1;
    int id = -1;
    for(int i = 1; i < (int)s.size(); i++)
    {
        while(~id && s[id+1] != s[i]) id = fail[id];
        if(s[id+1] == s[i]) id++;
        fail[i] = id;
    }
    /*
    cout << "prepalin" << endl;
    cout << var(s) << endl;
    for(int i = 0; i < (int)s.size(); i++)
    {
        cout << fail[i] << " ";
    }
    cout << endl;
    */
    return fail.back()+1;
}

void process()
{
    int lmx = 0, rmx = 0;
    if(R-L+1 > 0)
    {
        string sub = str.substr(L, R-L+1);
        lmx = prepalin(sub);
        reverse(sub.begin(), sub.end());
        rmx = prepalin(sub);
//        cerr << var(lmx) << var(rmx) << endl;
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
