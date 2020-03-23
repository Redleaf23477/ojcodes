// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

vector<int> up, down;

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
    string str; cin >> str;
    for(int i = 0; i < (int)str.size(); i++)
    {
        if(str[i] == '(') up.push_back(i);
        else down.push_back(i);
    }
}

void process()
{
    vector<int> ans;
    int u = 0, d = down.size()-1;
    while(u < (int)up.size() && d >= 0 && up[u] < down[d])
    {
        ans.push_back(up[u++]);
        ans.push_back(down[d--]);
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << ans.size() << endl;
        for(auto y : ans) cout << y+1 << " ";
        cout << endl;
    }
}
