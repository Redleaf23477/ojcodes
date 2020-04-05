// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

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

void process()
{
    vector<int> pos;
    pos.push_back(0);
    for(int i = 0; i < (int)str.size(); i++)
    {
        if(str[i] == 'R') pos.push_back(i+1);
    }
    pos.push_back(str.size()+1);
    int ans = 0;
    for(int i = 1; i < (int)pos.size(); i++)
        ans = max(ans, pos[i]-pos[i-1]);
    cout << ans << endl;
}

