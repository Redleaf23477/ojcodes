// by redleaf23477
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
    cin >> n >> str;
}

void process()
{
    string ans = str;
    int ak = 1;
    for(int k = 2; k <= n; k++)
    {
        string tmp;
        for(int i = 0; i <= n-k; i++)
            tmp.push_back(str[k+i-1]);
        string sub = str.substr(0, k-1);
        if((n-k+1)%2 == 1)
            reverse(sub.begin(), sub.end());
        tmp.insert(tmp.end(), sub.begin(), sub.end());
//        cout << var(k) << var(tmp) << endl;
        if(tmp < ans) ans = tmp, ak = k;
    }
    cout << ans << endl;
    cout << ak << endl;
}

