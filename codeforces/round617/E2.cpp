// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
string str;

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
    cin >> n >> str;
}

bool run(int color, bool print = false)
{
    vector<int> ans(n, 0);
    vector<char> bucket(color, 'a'-1);
    for(int i = 0; i < n; i++)
    {
        int dest = -1;
        for(int j = 0; j < color; j++)
        {
            if(str[i] >= bucket[j])
                if(dest == -1 || bucket[dest] < bucket[j])
                    dest = j;
        }
        if(dest == -1) return false;
        ans[i] = dest;
        bucket[dest] = str[i];
    }
    if(print)
    {
        for(auto x : ans) cout << x+1 << " ";
        cout << endl;
    }
    return true;
}

void process()
{
    for(int color = 1; color <= 26; color++)
    {
        if(run(color) == true)
        {
            cout << color << endl;
            run(color, true); break;
        }
    }
}

