#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

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
}

bool ok(int len)
{
    for(int pos = -1; pos < n;)
    {
        if(pos + len >= n) return true;
        bool good = false;
        for(int i = 1; i <= len; i++)
            if(str[pos+i] == 'R')
            {
                pos = pos+i; good = true; break;
            }
        if(good == false) return false;
    }
    return true;
}

void process()
{
    int low = 1, high = str.size()+1, mid, ans = str.size()+1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

